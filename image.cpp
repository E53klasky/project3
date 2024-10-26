#include <iostream> 
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include "image.h"
using namespace std; 


void image::TGAReader(string fileName) {

   //ifstream  filestream(fileName, ios_base::binary| ios::in);
    fstream fileStream(fileName, ios::binary | ios::in);
    

    if (!fileStream.is_open()) throw invalid_argument("No file");

    fileStream.read(&header.idLength, sizeof(header.idLength));
    fileStream.read(&header.colorMapType, sizeof(header.colorMapType));
    fileStream.read(&header.dataTypeCode, sizeof(header.dataTypeCode));
    fileStream.read((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
    fileStream.read((char *) &header.colorMapLength, sizeof(header.colorMapLength));
    fileStream.read( &header.colorMapDepth, sizeof(header.colorMapDepth));
    fileStream.read((char *) &header.xOrigin, sizeof(header.xOrigin));
    fileStream.read((char *) &header.yOrigin, sizeof(header.yOrigin));
    fileStream.read((char *) &header.width, sizeof(header.width)); 
    fileStream.read((char *) &header.height, sizeof(header.height)); 
    fileStream.read(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
    fileStream.read(&header.imageDescriptor, sizeof(header.imageDescriptor));
   
    //printHead(header);
    
    // I need to read in the pixels

   fileStream.close();
}



void image::TGAWriter(string outPutFile)
{ 
    fstream fileStream(outPutFile, ios::binary | ios::out);

    fileStream.read(&header.idLength, sizeof(header.idLength));
    fileStream.read(&header.colorMapType, sizeof(header.colorMapType));
    fileStream.read(&header.dataTypeCode, sizeof(header.dataTypeCode));
    fileStream.read((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
    fileStream.read((char *) &header.colorMapLength, sizeof(header.colorMapLength));
    fileStream.read( &header.colorMapDepth, sizeof(header.colorMapDepth));
    fileStream.read((char *) &header.xOrigin, sizeof(header.xOrigin));
    fileStream.read((char *) &header.yOrigin, sizeof(header.yOrigin));
    fileStream.read((char *) &header.width, sizeof(header.width)); //13,14
    fileStream.read((char *) &header.height, sizeof(header.height)); //15,16
    fileStream.read(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
    fileStream.read(&header.imageDescriptor, sizeof(header.imageDescriptor));
   
   // NEED TO WRITE OUT PIXEL DATA
       //printHead(header);
    fileStream.close();
   
}



unsigned int image::charToInt(unsigned char ltr)
{   // converts a char to an int
    return (unsigned int)(ltr - '\0');
}

unsigned char image::IntToChar(unsigned int num)
{   // converts an int to a char
    return (unsigned char) (num +'\0');
}


void setInt()
{   
    // THIS IS MEANT FOR PIXELS AND PIXEL Manunipulation
    cout<<"not done";
}

image::Header image::getHeader()
{
    return header;
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


int main()
{ 
    // testing right now
    string fileName = "../input/circles.tga";
    image myImage;
    myImage.TGAReader(fileName);
    myImage.getHeader();
  
    return 0;
}