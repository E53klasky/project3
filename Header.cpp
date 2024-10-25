#include <iostream>
#include "structHeader.h"
using namespace std; 

void printHead(const Header& head)
{
cout<<"The ID Length is: "<<head.idLength<<endl;
cout<<"The Color Map Type is: "<<head.colorMapDepth<<endl;
cout<<"The Data Type Code is: "<<head.dataTypeCode<<endl;
cout<<"The Color Map Origin is: "<<head.colorMapOrigin<<endl;
cout<<"The Color Map Length is: "<<head.colorMapLength<<endl;
cout<<"The Color Map Depth is: "<<head.colorMapDepth<<endl;
cout<<"The X-Origin is: "<<head.xOrigin<<endl;
cout<<"The Y-Origin is: "<<head.yOrigin<<endl;
cout<<"The Width is: "<<(short)head.width<<endl;
cout<<"The Height is: "<<(short)head.height<<endl;
cout<<"The Bits Per Pixel is: "<<head.bitsPerPixel<<endl;
cout<<"The Image Descriptor is: "<<head.imageDescriptor<<endl;
    
}

