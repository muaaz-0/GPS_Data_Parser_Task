#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#include "GPS_data_parser_header.h"
    
int main() 
{
    string Sentence="$GPGGA,002153.000,3342.6618,N,11751.3858,W,1,10,1.2,27.0,M,-34.2,M,,0000*5E";

   // string Sentence="$GPGGA,115739.00,4158.8441367,N,09147.4416929,W,4,13,0.9,255.747,M,-32.00,M,01,0000*6E";
    //string Sentence="$GPGGA,002153.000,3342.6618,N,11751.3858,W,1,10,1.2,27.0,M,-34.2,M,,0000*5E"   //invalid sentence
    
  
Start_Parsing(Sentence);
print();
if (unit_test1())
{
    cout<<"Test 1 Passed"<<endl;
}
else
{
cout<<"Test 1 Failed"<<endl;
}

        return 0;
}

  