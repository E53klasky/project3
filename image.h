#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// I will make a struct for pixel later
class image
{
public:
    struct Header {
    char idLength;
    char colorMapType;
    char dataTypeCode;
    short colorMapOrigin;
    short colorMapLength;
    char colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char bitsPerPixel;
    char imageDescriptor;
};


// readers and writers
void TGAReader(string fileName);
void TGAWriter(string outPutFile);

// conversion tools
unsigned int charToInt(unsigned char ltr);
unsigned char IntToChar(unsigned int num);


// to get an int
void setInt();

// geters and seters for the header
Header getHeader();
void setHeader(Header &header);

// need to add things with pixels
private:
    Header header;
};
