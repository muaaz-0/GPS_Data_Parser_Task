#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#include "GPS_data_parser_header.h"
    
int app_main() 
{
    //string Sentence="$GPGGA,002153.000,3342.6618,N,11751.3858,W,1,10,1.2,27.0,M,-34.2,M,,0000*5E";

    string Sentence="$GPGGA,115739.00,4158.8441367,N,09147.4416929,W,4,13,0.9,255.747,M,-32.00,M,01,0000*6E";
    //string Sentence="$GPGGA,002153.000,3342.6618,N,11751.3858,W,1,10,1.2,27.0,M,-34.2,M,,0000*5E"   //invalid sentence
    
  
Start_Parsing(Sentence);
print();

        return 0;
}
//------------------------------------------------ g++ main.c GPS_data_parser_header.c   ./a.exe
  