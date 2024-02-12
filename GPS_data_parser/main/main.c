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
   printf("the sentenceID is: %s\n",                                                   gpsData.sentenceID);
   printf("the lattitute is: %s\n",                                                       gpsData.UTCTime);
   printf("the UTC Time is: %s\n",                                                       gpsData.latitude);
   printf("the latitudeDirection is: %c\n",                                     gpsData.latitudeDirection);
   printf("the longitude is: %s\n",                                                     gpsData.longitude);
   printf("the longitudeDirection is: %c\n",                                   gpsData.longitudeDirection);
   printf("the QualityIndicator is: %d\n",                                       gpsData.QualityIndicator);
   printf("the Numofsatellites is: %d\n",                                         gpsData.Numofsatellites);
   printf("the horizontalDilution is: %lf\n",                                  gpsData.horizontalDilution);
   printf("the altitude is: %lf\n",                                                      gpsData.altitude);
   printf("the altitudeUnits is: %c\n",                                             gpsData.altitudeUnits);
   printf("the meanSeaLevelHeight is: %lf\n",                                  gpsData.meanSeaLevelHeight);
   printf("the geoidSeparationUnits is: %c\n",                               gpsData.geoidSeparationUnits);
   printf("the timeSinceLastDifferentialCorrection is: %s\n",gpsData.timeSinceLastDifferentialCorrection);
   printf("the differentialStationID is: %d\n",                             gpsData.differentialStationID);
   printf("the checksum is: %s\n",                                                       gpsData.checksum);
    return 0;
}
//------------------------------------------------g++ main.c GPS_data_parser_header.c   ./a.exe
  