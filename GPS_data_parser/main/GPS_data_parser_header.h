
enum Tokens {sentenceID, time, latitude, latDir, logitude, longitudeDir, QualityIndicator, Numofsattelites, horizontaldilution, altitude, altitudeUnits, meansealevelheight, geoidseparationUnits, timesincelastDC, differentialstationID};// enumeration of the tokens to use in switch statement

int Start_Parsing(string packet);
void Tokenize_data(char final_sentence[]);
void manage_missing(string packet);
bool unit_test1();
void print();

typedef struct {
	char  sentenceID[7];//GPSData->sentenceID

	char  UTCTime[10];

	char  latitude[10];

	char  latitudeDirection;

	char  longitude[11];

	char  longitudeDirection;

	int   QualityIndicator;

	int   Numofsatellites;

	float horizontalDilution;

	float altitude;

	char  altitudeUnits;

	float meanSeaLevelHeight;

	char  geoidSeparationUnits;

	float timeSinceLastDifferentialCorrection;

	char  differentialStationID[10];
	
	char  checksum[2];
} GPSData;

int parse_gps_data(const char *packet, GPSData *gpsData);
