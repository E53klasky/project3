#include <string>
#include <cstring>
#include <vector>
#include "image.h"
#include <fstream>
using namespace std;

int main()
{//
    string fileName = "../input/car.tga";
    image* myImage = new image;

    myImage->TGAReader(fileName);
    image::Header header = myImage->getHeader();
    myImage->printHeader(header);



    int k = 3000;
    // It works for i = 267928 for red
        //Segmentation fault(core dumped)
    // It works for i = 268966 for green
    // Segmentation fault (core dumped)

    // It works for i = B 267927 It works for i = B 267928 for blue doesn't work with that times 3 ??????
    // Segmentation fault (core dumped)



    myImage->scaleImageColor(k , "blue");







    // no core dump 
    //myImage->rotate180();

  //  myImage->scaleImageColor(k , "red");
    // It works for i = 268966
    // Segmentation fault (core dumped)



    // DO THIS AT THE END FOR EVERYTHING !!!!!!!!!!!!!!!!!!!!!!!









    return 0;
}