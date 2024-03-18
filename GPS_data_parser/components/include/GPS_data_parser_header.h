#ifndef GPS_DATA_PARSER_HEADER_H
#define GPS_DATA_PARSER_HEADER_H

enum Tokens {sentenceID, timeEnum, latitude, latDir, logitude, longitudeDir, QualityIndicator, Numofsattelites, horizontaldilution, altitude, altitudeUnits, meansealevelheight, geoidseparationUnits, timesincelastDC, differentialstationID};// enumeration of the tokens to use in switch statement

int Parse_gps_Data(string packet);
void manage_missing(string packet);
void Tokenize_data(char final_sentence[]);

void print();

struct GPSData{
    string sentenceID;
    string time;
    string latitude;
    char latDir;
    string longitude;
    char longDir;
    unsigned int QualityIndicator;
    unsigned int NumofSat;
    string horizontaldilution;
    string altitude;
    char altitudeUnits;
    string meansealevelheight;
    char geoidseparationUnits;
    string timesincelastDC;
    string differentialstationID;
    string checksum;

};

extern GPSData GPSdata;

// Other function declarations...

#endif 