#include <string>
#include <cstring>
#include <vector>
#include "image.h"
#include <fstream>
using namespace std;

/// I THINK I SHOULD DELET ALL THEM AFTER EACH TASK AND SET TO NULL POINTERS 

// multiply two images


  // example !!!!!!!!!!!!
  // string fileName = "../input/car.tga";
  // image* myImage = new image;
  // myImage->TGAReader(fileName);
  // image::Header header = myImage->getHeader();

void taskOne(image& layerOne , image& patternOne)
{
  layerOne.TGAReader("../input/layer1.tga");
  patternOne.TGAReader("../input/pattern1.tga");

  // need to make a copy construtor
  // result

  layerOne.multiply(patternOne); // here may be a problem changing layer 1!!!!!???
  //layerOne changes
  layerOne.TGAWriter("../output/part1.tga");
  // test
  image* example = new image;
  example->TGAReader("../examples/EXAMPLE_part1.tga");
  example->carbonCopies(layerOne);

}


void taskTwo(image& layerTwo , image& car)
{
  // what does top layer and buttom layer mean 
  layerTwo.TGAReader("../input/layer2.tga");
  car.TGAReader("../input/car.tga");
  // need to make a copy construtor
  car.subtract(layerTwo);

// result
  car.TGAWriter("../output/part2.tga");
  image* example = new image;
  example->TGAReader("../examples/EXAMPLE_part2.tga");
  example->carbonCopies(car);

}



void taskThree(image& layerOne , image& patternTwo , image& text)
{
  // later problem make sure to have layer1 unchanged!!!!!!!!!!!!!!!!!!
  layerOne.TGAReader("i../nput/layer1.tga");
  patternTwo.TGAReader("../input/pattern2.tga");
  text.TGAReader("../input/text.tga");
  // 
  layerOne.multiply(patternTwo);
  text.screen(layerOne);

  text.TGAWriter("../output/part3.tga");

}


void taskFour(image& layerTwo , image& circles , image& patternTwo)
{
  layerTwo.TGAReader("../input/layer2.tga");
  circles.TGAReader("../input/circles.tga");
  patternTwo.TGAReader("../input/pattern2.tga");

  layerTwo.multiply(circles);

  patternTwo.subtract(layerTwo);
  patternTwo.TGAWriter("../output/part4.tga");

}


void taskFive(image& layerOne , image& patterOne)
{
  layerOne.TGAReader("../input/layer1.tga");
  patterOne.TGAReader("../input/pattern1.tga");
  layerOne.overlay(patterOne);
  layerOne.TGAWriter("../output/part5.tga");

}


void taskSix(image& car)
{
  car.TGAReader("input/car.tga");
  int num = 200;
  car.add(num , "green");
  car.TGAWriter("output/part6.tga");
}


void taskSeven(image& car)
{
  car.TGAReader("input/car.tga");
  int scaleOne = 4;
  int scaleTwo = 0;
  car.scaleImageColor(scaleOne , "red");
  car.scaleImageColor(scaleTwo , "blue");
  car.TGAWriter("output/part7.tga");
}

// need to think about this??????
void taskEight(image& carOne , image& carTwo , image& carThree)
{
  carOne.TGAReader("input/car.tga");
  carTwo.TGAReader("input/car.tga");
  carThree.TGAReader("input/car.tga");

  carOne.onlyColor("red");
  carTwo.onlyColor("green");
  carThree.onlyColor("blue");


  carOne.TGAWriter("output/“part8_r.tga");
  carTwo.TGAWriter("output/“part8_g.tga");
  carThree.TGAWriter("output/“part8_b.tga");

}

void taskNine(image& red , image& green , image& blue)
{
  red.TGAReader("input/layer_red.tga");
  green.TGAReader("input/layer_green.tga");
  blue.TGAReader("input/layer_blue.tga");
  red.combineThree(green , blue);
  red.TGAWriter("output/task9.tga");
}




void taskTen(image& textTwo)
{
  textTwo.TGAReader("input/text2.tga");
  textTwo.rotate180();
  textTwo.TGAWriter("output/task10");

}


// void bonus()
// {

// }



int main()
{

 // 1.3 test them
 // 1.4 see TA if needed????????
 // 2. debug them
 // 3. make bouns test it and free memory
 // 4. see a TA before submiting it if you can 

  image* layerOne = new image;
  image* patternOne = new image;


  //taskOne(*layerOne , *patternOne);


  image* layerTwo = new image;
  image* car = new image;

  taskTwo(*layerTwo , *car);

  // THERE IS SOMETHING WRONG WITH MY DECSTRUCTOR IT IS DOING SOMETHING WEIRD
  // delete layerOne;
  // delete patternOne;
  // delete layerTwo;
  // delete car;
  layerOne = nullptr;
  patternOne = nullptr;
  layerTwo = nullptr;
  car = nullptr;
  cout << "code finished \n";



  return 0;
}