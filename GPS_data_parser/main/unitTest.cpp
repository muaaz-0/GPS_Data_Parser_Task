#include <iostream>
#include <string.h>
#include <stdio.h>
/*#include "freertos/FreeRTOS.h"
//#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"*/
using namespace std;
#include "GPS_data_parser_header.h"

bool unit_test1();
extern "C" void app_main(void)
{
    string Sentence="$GPGGA,002153.000,3342.6618,N,11751.3858,W,1,10,1.2,27.0,M,-34.2,M,,0000*5E";

   // string Sentence="$GPGGA,115739.00,4158.8441367,N,09147.4416929,W,4,13,0.9,255.747,M,-32.00,M,01,0000*6E";
    //string Sentence="$GPGGA,002153.000,3342.6618,N,11751.3858,W,1,10,1.2,27.0,M,-34.2,M,,0000*5E"   //invalid sentence
    
  
Parse_gps_Data(Sentence);
print();
if (unit_test1())
{
    cout<<"Test 1 Passed"<<endl;
}
else
{
cout<<"Test 1 Failed"<<endl;
}
}

bool unit_test1() // This function tests the values of the output by comparing with the input parameter and return true if all values are equal
{
    return (GPSdata.time == "002153.000") &&
           (GPSdata.latitude == "3342.6618") &&
           (GPSdata.latDir == 'N') &&
           (GPSdata.longitude == "11751.3858") &&
           (GPSdata.longDir == 'W') &&
           (GPSdata.QualityIndicator == 1) &&
           (GPSdata.NumofSat == 10) &&
           (GPSdata.horizontaldilution == "1.2") &&
           (GPSdata.altitude == "27.0") &&
           (GPSdata.altitudeUnits == 'M') &&
           (GPSdata.meansealevelheight == "-34.2") &&
           (GPSdata.geoidseparationUnits == 'M') &&
           (GPSdata.timesincelastDC == "#") &&
           (GPSdata.differentialstationID == "0000") &&
           (GPSdata.checksum == "5E");
}
  