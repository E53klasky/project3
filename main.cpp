#include <string>
#include <cstring>
#include <vector>
#include "image.h"
#include <fstream>
using namespace std;

int main()
{
    string fileName = "../input/circles.tga";
    image* myImage = new image;

    myImage->TGAReader(fileName);
    image::Header header = myImage->getHeader();
    myImage->printHeader(header);

    delete myImage;
    myImage = nullptr;
    return 0;
}