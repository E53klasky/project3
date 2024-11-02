#include <iostream> 
#include <vector>
#include <string>
#include <fstream>
#include "image.h"
#include <algorithm> 
using namespace std;


// When you WRITE IT OVER RIGHTS THE FILES SETTING IT TO 0 !!!!!!!!!!!!!!

void image::TGAReader(const string fileName) {

    fstream fileStream(fileName , ios::in | ios::binary);


    if (header == nullptr) {

        header = new Header;
    }

    if (!fileStream.is_open()) throw invalid_argument("No file");

    fileStream.read(&header->idLength , sizeof(header->idLength));
    fileStream.read(&header->colorMapType , sizeof(header->colorMapType));
    fileStream.read(&header->dataTypeCode , sizeof(header->dataTypeCode));
    fileStream.read((char*)&header->colorMapOrigin , sizeof(header->colorMapOrigin));
    fileStream.read((char*)&header->colorMapLength , sizeof(header->colorMapLength));
    fileStream.read(&header->colorMapDepth , sizeof(header->colorMapDepth));
    fileStream.read((char*)&header->xOrigin , sizeof(header->xOrigin));
    fileStream.read((char*)&header->yOrigin , sizeof(header->yOrigin));
    fileStream.read((char*)&header->width , sizeof(header->width));
    fileStream.read((char*)&header->height , sizeof(header->height));
    fileStream.read(&header->bitsPerPixel , sizeof(header->bitsPerPixel));
    fileStream.read(&header->imageDescriptor , sizeof(header->imageDescriptor));

    // pixels
    fileStream.seekg(18 , ios::beg);

    this->pixels = new char[header->height * header->width * 3];

    // Read pixel data
    fileStream.read(this->pixels , header->height * header->width * 3);

    // prints out the image for testing
    // for (int i = 0; i < 1000; ++i) {
    //     unsigned char red = pixels[i * 3];
    //     unsigned char green = pixels[i * 3 + 1];
    //     unsigned char blue = pixels[i * 3 + 2];
    //     cout << "Pixel " << i << ": R=" << (int)red << " G=" << (int)green << " B=" << (int)blue << endl;
    // }

    fileStream.close();

}


// When you WRITE IT OVER RIGHTS THE FILES SETTING IT TO 0 !!!!!!!!!!!!!!
void image::TGAWriter(string outPutFile)
{
    // fstream fileStream(outPutFile , ios::binary | ios::out);

    // fileStream.write(&header->idLength , sizeof(header->idLength));
    // fileStream.write(&header->colorMapType , sizeof(header->colorMapType));
    // fileStream.write(&header->dataTypeCode , sizeof(header->dataTypeCode));
    // fileStream.write((char*)&header->colorMapOrigin , sizeof(header->colorMapOrigin));
    // fileStream.write((char*)&header->colorMapLength , sizeof(header->colorMapLength));
    // fileStream.write(&header->colorMapDepth , sizeof(header->colorMapDepth));
    // fileStream.write((char*)&header->xOrigin , sizeof(header->xOrigin));
    // fileStream.write((char*)&header->yOrigin , sizeof(header->yOrigin));
    // fileStream.write((char*)&header->width , sizeof(header->width));
    // fileStream.write((char*)&header->height , sizeof(header->height));
    // fileStream.write(&header->bitsPerPixel , sizeof(header->bitsPerPixel));
    // fileStream.write(&header->imageDescriptor , sizeof(header->imageDescriptor));

    //fileStream.close();

}



unsigned int image::charToInt(unsigned char ltr)
{   // converts a char to an int
    return static_cast<unsigned int>(ltr);
}

unsigned char image::IntToChar(unsigned int num)
{   // converts an int to a char
    return static_cast<unsigned char>(num);
}


void image::setInt()
{
    // THIS IS MEANT FOR PIXELS AND PIXEL Manunipulation
    cout << "not done";
}

// Header things now

image::Header image::getHeader() const
{
    return *header;
}

void image::setHeader(Header& header)
{
    char idLength = header.idLength;
    char colorMapType = header.colorMapType;
    char dataTypeCode = header.dataTypeCode;
    short colorMapOrigin = header.colorMapOrigin;
    short colorMapLength = header.colorMapLength;
    char colorMapDepth = header.colorMapDepth;
    short xOrigin = header.xOrigin;
    short yOrigin = header.yOrigin;
    short width = header.width;
    short height = header.height;
    char bitsPerPixel = header.bitsPerPixel;
    char imageDescriptor = header.imageDescriptor;
}

void image::printHeader(const Header& header)
{
    cout << "The ID Length is: " << header.idLength << endl;
    cout << "The Color Map Type is: " << header.colorMapDepth << endl;
    cout << "The Data Type Code is: " << header.dataTypeCode << endl;
    cout << "The Color Map Origin is: " << header.colorMapOrigin << endl;
    cout << "The Color Map Length is: " << header.colorMapLength << endl;
    cout << "The Color Map Depth is: " << header.colorMapDepth << endl;
    cout << "The X-Origin is: " << header.xOrigin << endl;
    cout << "The Y-Origin is: " << header.yOrigin << endl;
    cout << "The Width is: " << (short)header.width << endl;
    cout << "The Height is: " << (short)header.height << endl;
    cout << "The Bits Per Pixel is: " << header.bitsPerPixel << endl;
    cout << "The Image Descriptor is: " << header.imageDescriptor << endl;
}


// pixel manipulation
void image::multiply()
{
    cout << "NOT DONE";
}

void image::add(int scalar , string color)
{ // increases red, green, or blue based off what you want
    size_t numPixels = header->width * header->height;
    for (size_t i = 0; i < numPixels; ++i) {
        if (color == "red") {
            pixels[i * 3] = min(255 , max(0 , pixels[i * 3] + scalar));
        }
        else if (color == "green") {
            pixels[i * 3 + 1] = min(255 , max(0 , pixels[i * 3 + 1] + scalar));
        }
        else if (color == "blue") {
            pixels[i * 3 + 2] = min(255 , max(0 , pixels[i * 3 + 2] + scalar));
        }
    }

}

void image::subtract(const image& diffImage) {
    if (header->width != diffImage.header->width || header->height != diffImage.header->height) {
        throw invalid_argument("This doesn't work");
    }

    size_t numPixels = header->width * header->height * 3; // Multiply by 3 to account for RGB components
    for (size_t i = 0; i < numPixels; ++i) {
        pixels[i] = max(0 , pixels[i] - diffImage.pixels[i]);
    }
}

void image::flip()
{
    cout << "NOT DONE";
}





