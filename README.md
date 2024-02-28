The project consists of three files containing code:

"main.cpp"
"GPS_data_parser_header.cpp"
"GPS_data_parser_header.h"

In main.cpp:
There are some header files and the main function. In the main function, a few sentences are stored in the string variable "Sentence".
A Start_Parsing() function is called which is declared in the "GPS_data_parser_header.h" file (The explanation is given below).
A print function is declared which will print the values of each parameter of the GGA sentence
An if() statement will take the return value of the unit_test function telling whether the test is passed or not.

In GPS_data_parser_header.h:
An Enumeration is used which will initialize the parameters of the sentence from 0 to onwards which will be used in the switch statement case value during tokenization. 
This is used to increase the readability of the code.
Moreover, some functions are declared which will be called later.

int Parse_gps_Data(string packet);
void manage_missing(string packet);
void Tokenize_data(char final_sentence[]);
bool unit_test1();
void print();

A struct is created to store the individual parameters of the GPS data.

In GPS_data_parser_header.cpp:
Some variables are declared globally because they are used in multiple functions.
The functions which are declared in "GPS_data_parser_header.h" are defined in this file.
First, the "Parse_gps_Data(string packet)" function is defined which takes a string variable as an argument. Then first it calculates the checksum by continuously XORing each element in the string packet until an asterisk "*" or a NULL is not found.
Next the conditional if statement is used to check if the last element in the previous packet is an "asterisk" Then the next two elements will be stored in the provided checksum array. else the sentence is not correct.
Then the no of commas is extracted, and the first packet "GPGGA" and not of commas is checked for the NMEA GGA sentence.
After that, the packet integrity is validated by comparing the calculated checksum and the provided checksum.
if the sentence is valid then the manage missing function is called.

In "manage_missing(packet)" function,
First, the data between the $ and * is taken out as parameters do not include these two elements.
After that, the missing parameter is replaced by a # symbol, the first packet is copied to another character array, then the missing parameter is recognized by identifying two consecutive commas, and the missing parameter is stored with the position of the first comma and also the no of missing parameters are identified.
Then the missing position is replaced by the # using the concept of adding a parameter between arrays. In case of multiple missing parameters, every time the # is added the position of the next missing parameter is modified as adding an element in the array will also modify the missing position of the next element. When all missing parameters are managed the Tokenize_data() function is called.

In Tokenize_data() function:
The sentence is tokenized based on the delimiter "," and each token is stored in the individual member of the struct.

Print():
A print function is defined to print the individual parameters when they are called.

Unit_test1() function:
A unit test function is defined which will check if the parsed data is correct or not if correct it will return true if not then return false.
