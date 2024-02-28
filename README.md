The project consists of three files containing code:

"main.cpp"
"GPS_data_parser_header.cpp"
"GPS_data_parser_header.h"

In main.cpp:
There are some header files and the main function. In the main function, a few sentences are stored in the string variable "Sentence".
A Start_Parsing() function is called which is declared in the "GPS_data_parser_header.h" file (The explanation is given below).
A print function is declared which will print the values of each parameter of the GGA sentence
An if() statement will take the return value of the unit_test function telling whether the test is passed or not.

In GPS_data_parser_header.cpp:
An Enumeration is used which will initialize the parameters of the sentence from 0 to onwards which will be used in the switch statement case value during tokenization. 
This is used to increase the readability of the code.
Moreover, some functions are declared which will be called later.

int Parse_gps_Data(string packet);
void manage_missing(string packet);
void Tokenize_data(char final_sentence[]);
bool unit_test1();
void print();

A struct is created to store the individual parameters of the GPS data.
