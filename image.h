#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

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



void TGAReader(string fileName);
void TGAWriter(string outPutFile);

unsigned int charToInt(unsigned char ltr);
unsigned char IntToChar(unsigned int num);

void setInt();

void printHead(const Header& header);
void setHeader(Header &header);

private:
    Header header;
};
