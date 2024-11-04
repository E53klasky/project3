#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
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

    // geters and seters for  the header
    Header getHeader() const;
    void setHeader(Header& header);
    void printHeader(const Header& header);

    // need to add things with pixels

    // maniplualtion of functions 


    void multiply(const image& diffImage);
    void add(int num , const string& color);
    void scaleImageColor(int scalar , const string color);
    void subtract(const image& diffImage);
    void rotate180();

    // scaling colors


    // TESTING
    void carbonCopies(const image& diffImage);

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


};
