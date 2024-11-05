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



    // maniplualtion of functions 
    void multiply(const image& diffImage);
    void add(int num , const string& color);
    void scaleImageColor(int scalar , const string color);
    void subtract(const image& diffImage);
    void rotate180();
    void overlay(const image& diffImage);
    void screen(const image& diffImage);
    void combineThree(const image& green, const image& blue);


    // extra credit
   // combinefour(); 


    // TESTING
    void printThatImage();
    void carbonCopies(const image& diffImage);

       // destructor 
    ~image() {
        delete[] imageData;
        delete header;
        delete[] pixels;
    }

    // copy constuctor
    // image(const image& diffImage);
    // // {

    // // }

    // // image operator = (const image& diffImage);
    // // {
    // //     image copy = image()   
    // // }



private:
    unsigned char* imageData;
    Header* header;
    char* pixels;


};
