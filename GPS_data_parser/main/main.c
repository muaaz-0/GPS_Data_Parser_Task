#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "GPS_data_parser_header.h"
    
int main()
{
    const char *packet="$GPGGA,002153.000,3342.6618,N,11751.3858,W,1,10,1.2,27.0,M,-34.2,M,,0000*5E";
    printf("The Sentence is: %s\n",packet);
    GPSData gpsData;

    parse_gps_data(packet,&gpsData);

    printf("SentenceID is: %s\n",                                                   gpsData.sentenceID);

    printf("lattitute is: %s\n",                                                       gpsData.UTCTime);

    printf("UTC Time is: %s\n",                                                       gpsData.latitude);

    printf("Latitude Direction is: %c\n",                                    gpsData.latitudeDirection);

    printf("Longitude is: %s\n",                                                     gpsData.longitude);

    printf("LongitudeDirection is: %c\n",                                   gpsData.longitudeDirection);

    printf("QualityIndicator is: %d\n",                                       gpsData.QualityIndicator);

    printf("NumBer of Satellites is: %d\n",                                    gpsData.Numofsatellites);

    printf("HorizontalDilution is: %lf\n",                                  gpsData.horizontalDilution);

    printf("Altitude is: %lf\n",                                                      gpsData.altitude);

    printf("AltitudeUnits is: %c\n",                                             gpsData.altitudeUnits);

    printf("Mean SeaLevel Height is: %lf\n",                                gpsData.meanSeaLevelHeight);

    printf("Geoid Separation Units is: %c\n",                             gpsData.geoidSeparationUnits);

    printf("Time Since Last Differential Correction is: %s\n",gpsData.timeSinceLastDifferentialCorrection);

    printf("Differential Station ID is: %d\n",                           gpsData.differentialStationID);
    
    printf("Checksum is: %s\n",                                                       gpsData.checksum);
        return 0;
}
//------------------------------------------------g++ main.c GPS_data_parser_header.c   ./a.exe
  