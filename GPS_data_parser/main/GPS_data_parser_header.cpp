#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#include "GPS_data_parser_header.h"


char calculated_checksum_hex[3];
GPSData GPSdata;                             //Creating the variable of Structure
int Start_Parsing(string packet)

{
    // Calculate checksum
    int i=0;
    unsigned int checksum = 0;
    for (i = 1; packet[i] != '*' && packet[i] != '\0'; i++) // This loop runns until a steric is found or a NULL char
    {
        checksum ^= packet[i];                             // XOR operator is applied on every element in the packet to find checksum
    }
    
char provided_checksum[2];
      if (packet[i]=='*') //extract provided checksum
        {
          provided_checksum[0]=packet[i+1];  //store first element next to steic in provided_checksum[0]
          provided_checksum[1]=packet[i+2];  //store second ....               ..   provided_checksum[0]
          provided_checksum[2]='\0';         //store last element as null
        }
         // check if steric is present or not if not then no checksum found
    

    if (packet[i] != '*')                   //If steric is not found this means sentence is not correct
    {
        cout<<"Checksum Not Found! '-': "<<endl;
        return 0;
    }


    // Compute checksum in hexadecimal
    
    snprintf(calculated_checksum_hex, sizeof(calculated_checksum_hex), "%02X", checksum); // converters the decimal value to hexadecimal value



    int commas = 0;
    for (int i = 0; i < strlen(packet.c_str()); i++) // extract the number of commas in the packet
    {
        if (packet[i] == ',')                        // if comma found then increment the commas variable
        {
            commas++;
        }       
    }
    // This section compares the first 7 character of the packet with GPGGA to confirm sentence as GGA and check if threre are 14 commas

    if (strncmp(packet.c_str(), "$GPGGA,", 7) == 0 && commas == 14 && packet[i] == '*')//c_str() function converts the string packet to a const character
     {
        cout<<"The sentence is in GGA format: \n"<<endl;

    } else {
       cout<<"The sentence is not in GGA format: \n"<<endl;
        return 0;
    }

    // Check packet integrity
    
    if (strcmp(provided_checksum, calculated_checksum_hex) == 0) {
        cout<<"Packet integrity valid: chksum \n"<< calculated_checksum_hex<<endl;

        manage_missing(packet);  //if packet integrity valid then manage manage missing function is called
    } else {
        cout<<"Packet integrity not valid: chksum \n"<< calculated_checksum_hex<<endl;   // if packet intefrity is not valid then return 0
        //return 0;
        //manage_missing(packet); 
    }
    return 0;
}


void manage_missing(string packet) {

 // Extract packet data excluding '$' and '*'
    char packet2[strlen(packet.c_str()) - 3];
    int k = 0;
    for (int i = 1; packet[i] != '*'; i++) {
        packet2[k++] = packet[i];
    }
    packet2[k] = ','; // Adding comma at the last point to make last data as token
    packet2[k+1]='\0';

    cout<<packet2<<endl;

//onwards this section the missing packets will be replaced by a '#'

 char MIS = '#';
    
    int size= strlen(packet2);
   
    char final_sentence[size + 1];      //  Increase size by 1 to accommodate the new character

    strcpy(final_sentence, packet2);    //  Copy the packet to final sentence that will contained managed data

   

    int mispos[size];                    //  Creating array to store position of missing character
    int empty_count = 0;                 //  Counter to count the number of missing positions

    for(int pos = 0; pos < size; pos++) {
        if(final_sentence[pos] == ',' && final_sentence[pos + 1] == ',') // checks for the consective commas
        {
            mispos[empty_count] = pos + 1;                               // if found consecutive comma then store next position for missing data
            empty_count++;
        }
    }
    //cout << "Number of empty positions: " << empty_count << endl;

    for(int j = 0; j < empty_count; j++)            //loop to store # on missing positions, run till no of empty elements
    {                                               //As when first element is added the missing positions will be updated so there need to update the position

        int pos=mispos[j] + j;                      // Update the missing position according to missing count
                                                            
        for(int i = size; i >= pos; i--)            // the loop will run in reverse order until position of missing element is found
        {
        final_sentence[i] = final_sentence[i - 1];  // elements are stored in one position next 
    }
    final_sentence[pos] = MIS;                      // replace # on the missing postion
    size++;                                         // Increase size of array

    }
//cout<<"final sentence is : "<<final_sentence<<endl;
   
    Tokenize_data(final_sentence);                  // CALL THE FUNCTION TO PARSE FINAL SENTENCE

                                                            
}

int parse_gps_data(string Sentence) {
    

    // Extract packet data excluding '$' and '*'
    char packet2[strlen(packet) - 3];
    int k = 0;
    for (int i = 1; packet[i] != '*'; i++) {
        packet2[k++] = packet[i];
    }
    packet2[k] = '\0';

    for(int f=0; f<=strlen(packet2); f++)
    {
        if(packet2[f]==',' && packet2[f+1]==',')
        {

        }
    }

    // Tokenize packet data
    char packet_copy[max_length];
    strncpy(packet_copy, packet2, max_length);
    char *token;
    token = strtok(packet_copy, ",");
    int j = 0;

    // Parse tokenized data
    while (token != NULL && j < 15) {
        switch (j) {
            case 0:

                strncpy(gpsData->sentenceID, token, sizeof(gpsData->sentenceID) - 1);
                gpsData->sentenceID[sizeof(gpsData->sentenceID) - 1] = '\0';
                break;

            case 1:
            if (j+1!=empty_data_pos[j])
               { strncpy(gpsData->UTCTime, token, sizeof(gpsData->UTCTime) - 1);
                gpsData->UTCTime[sizeof(gpsData->UTCTime) - 1] = '\0';}
            else
            strcpy(gpsData->UTCTime, empty );
            printf("th time is: %s\n", gpsData->UTCTime);
                break;
            case 2:
                strncpy(gpsData->latitude, token, sizeof(gpsData->latitude));
                gpsData->latitude[sizeof(gpsData->latitude) - 1] = '\0';
                break;
            case 3:
                gpsData->latitudeDirection = token[0];
                break;
            case 4:
                strncpy(gpsData->longitude, token, sizeof(gpsData->longitude) - 1);
                gpsData->longitude[sizeof(gpsData->longitude) - 1] = '\0';
                break;
            case 5:
                gpsData->longitudeDirection = token[0];
                break;
            case 6:
                gpsData->QualityIndicator = atoi(token);
                break;
            case 7:
                gpsData->Numofsatellites = atoi(token);
                break;
            case 8:
                gpsData->horizontalDilution = atof(token);
                break;
            case 9:
                gpsData->altitude = atof(token);
                break;
            case 10:
                gpsData->altitudeUnits = token[0];
                break;
            case 11:
                gpsData->meanSeaLevelHeight = atof(token);
                break;
            case 12:
                gpsData->geoidSeparationUnits = token[0];
                break;
            case 13:
                gpsData->timeSinceLastDifferentialCorrection = atof(token);
                break;
            case 14:
            
                strncpy(gpsData->differentialStationID, token, sizeof(gpsData->differentialStationID));
                break;
        }
        token = strtok(NULL, ",");
        j++;
    }

    // Copy calculated checksum
    strncpy(gpsData->checksum, calculated_checksum_hex, sizeof(gpsData->checksum));
    return 0;
        }