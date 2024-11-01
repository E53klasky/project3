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

    // add a desctutor for pixels



   // readers and writers
    void TGAReader(const string fileName);
    void TGAWriter(string outPutFile);

    // conversion tools
    unsigned int charToInt(unsigned char ltr);
    unsigned char IntToChar(unsigned int num);

    // to get an int of the data
    void setInt();

    // geters and seters for  the header
    Header getHeader() const;
    void setHeader(Header& header);
    void printHeader(const Header& header);

    // need to add things with pixels

    // maniplualtion of functions 
    void multiply();
    void add();
    void subtract();
    void flip();

    // destructor 
    ~image() {
        delete[] imageData;
        delete header;
        delete[] pixels;
    }



private:
    unsigned char* imageData;
    Header* header;
    char* pixels;
    unsigned int red , blue , green;

};
