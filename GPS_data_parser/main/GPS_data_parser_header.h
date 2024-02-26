
enum Tokens {sentenceID, time, latitude, latDir, logitude, longitudeDir, QualityIndicator, Numofsattelites, horizontaldilution, altitude, altitudeUnits, meansealevelheight, geoidseparationUnits, timesincelastDC, differentialstationID};// enumeration of the tokens to use in switch statement

int Start_Parsing(string packet);
void Tokenize_data(char final_sentence[]);
void manage_missing(string packet);
bool unit_test1();
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