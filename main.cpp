#include <string>
#include <cstring>
#include <vector>
#include "image.h"
#include <fstream>
using namespace std;

/// I THINK I SHOULD DELET ALL THEM AFTER EACH TASK AND SET TO NULL POINTERS 

// multiply two images
void taskOne(image& layerOne , image& patternOne)
{
  layerOne.TGAReader("input/layer1.tga");
  patternOne.TGAReader("input/pattern1.tga");
  // need to make a copy construtor
  // result
   // layerOne.multiply(patternOne); // here may be a problem changing layer 1!!!!!???

 // patternOne.TGAWriter("input/part1.tga");


}


void taskTwo(image& layerTwo , image& car)
{
  layerTwo.TGAReader("input/“layer2.tga");
  car.TGAReader("input/car.tga");
  // need to make a copy construtor
  //layerTwo.multiply(car);
  // result
 // patternOne.TGAWriter("output/part1.tga");
}



void taskThree(image& layerOne , image& patternTwo)
{
  // later problem make sure to have layer1 unchanged!!!!!!!!!!!!!!!!!!
  layerOne.TGAReader("input/layer1.tga");
  patternTwo.TGAReader("input/pattern2.tga");
  // 
  //layerOne.multiply(image& pattern2);
  //    layerOne.screen(image& pattern2) 
   // layerOne.TGAWriter("output/part1.tga");


}


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
  // 1. what is left finish task 
  // 1.1 just send them new ones to methods each time
  // 1.2 delet and set them eqaul to nonptr at the end of either the method or the main method
  // 1.3 test them
  // 1.4 see TA if needed????????
  // 2. debug them
  // 3. make bouns test it and free memory
  // 4. see a TA before submiting it if you can 
  image* layerOne = new image;
  image* patternOne = new image;
  image* layerTwo = new image;
  image* car = new image;




  return 0;
}