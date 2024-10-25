#include <iostream>
#include "structHeader.h"
using namespace std; 

void printHead(const Header& head)
{
cout<<"The ID Length is: "<<(char)head.idLength<<endl;
cout<<"The Color Map Type is: "<<(char)head.colorMapDepth<<endl;
cout<<"The Data Type Code is: "<<(char)head.dataTypeCode<<endl;
cout<<"The Color Map Origin is: "<<(short)head.colorMapOrigin<<endl;
cout<<"The Color Map Length is: "<<(short)head.colorMapLength<<endl;
cout<<"The Color Map Depth is: "<<(char)head.colorMapDepth<<endl;
cout<<"The X-Origin is: "<<(short)head.xOrigin<<endl;
cout<<"The Y-Origin is: "<<(short)head.yOrigin<<endl;
cout<<"The Width is: "<<(short)head.width<<endl;
cout<<"The Height is: "<<(short)head.height<<endl;
cout<<"The Bits Per Pixel is: "<<(char)head.bitsPerPixel<<endl;
cout<<"The Image Descriptor is: "<<(char)head.imageDescriptor<<endl;
    
}

