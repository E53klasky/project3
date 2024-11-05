#include <string>
#include <cstring>
#include <vector>
#include "image.h"
#include <fstream>
using namespace std;


// void taskOne()
// {

// }


// void taskTwo()
// {

// }



// void taskThree()
// {

// }


// void taskFour()
// {

// }


// void taskFive()
// {

// }


// void taskSix()
// {

// }


// void taskSeven()
// {

// }

// void taskEight()
// {

// }


// void tasknine();
// {

// }

// void taskTen();
// {

// }


// void bonus()
// {

// }




int main()
{
  string fileName = "../input/car.tga";
  image* myImage = new image;

  myImage->TGAReader(fileName);
  image::Header header = myImage->getHeader();
  myImage->printHeader(header);

  delete myImage;
  myImage = nullptr;


  return 0;
}