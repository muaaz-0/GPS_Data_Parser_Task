#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "GPS_data_parser_header.h"

int parse_gps_data(const char *packet, GPSData *gpsData) {
    // Calculate checksum
    unsigned int checksum = 0;
    for (int i = 1; packet[i] != '*' && packet[i] != '\0'; i++) {
        checksum ^= packet[i];
    }

    // Verify checksum presence
    int i = 0;
    while (packet[i] != '*' && packet[i] != '\0') {
        i++;
    }
    if (packet[i] != '*') {
        printf("No checksum found! '-' :");
        return -1;
    }

    // Extract provided checksum
    char provided_checksum[3];
    strncpy(provided_checksum, packet + i + 1, 2);
    provided_checksum[2] = '\0';

    // Compute checksum in hexadecimal
    char calculated_checksum_hex[3];
    snprintf(calculated_checksum_hex, sizeof(calculated_checksum_hex), "%02X", checksum);

    // Check sentence format
    int commas = 0;
    for (int i = 0; i < strlen(packet); i++) {
        if (packet[i] == ',') {
            commas++;
        }
    }
    if (strncmp(packet, "$GPGGA,", 7) == 0 && commas == 14 && packet[i] == '*') {
        printf("The sentence is in GGA format: "); // GGA sentence
    } else {
        printf("The sentence is not in GGA format: ");
    }

    // Check packet integrity
    if (strcmp(provided_checksum, calculated_checksum_hex) == 0) {
        printf("Packet integrity valid\n");
    } else {
        printf("Packet integrity not valid\n");
    }

    // Extract packet data excluding '$' and '*'
    char packet2[strlen(packet) - 3];
    int k = 0;
    for (int i = 1; packet[i] != '*'; i++) {
        packet2[k++] = packet[i];
    }
    packet2[k] = '\0';

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
                strncpy(gpsData->UTCTime, token, sizeof(gpsData->UTCTime) - 1);
                gpsData->UTCTime[sizeof(gpsData->UTCTime) - 1] = '\0';
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
