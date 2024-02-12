#define max_length 128

typedef struct {
	char sentenceID[7];//GPSData->sentenceID
	char UTCTime[10];
	char latitude[10];
	char latitudeDirection;
	char longitude[11];
	char longitudeDirection;
	int QualityIndicator;
	int Numofsatellites;
	float horizontalDilution;
	float altitude;
	char altitudeUnits;
	float meanSeaLevelHeight;
	char geoidSeparationUnits;
	float timeSinceLastDifferentialCorrection;
	char differentialStationID[10];
	char checksum[2];
} GPSData;

int parse_gps_data(const char *packet, GPSData *gpsData);