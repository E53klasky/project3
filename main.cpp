#include <string>
#include <cstring>
#include <vector>
#include "image.h"
#include <fstream>
#include <ctime>
#include <chrono>
using namespace std;

inline long long systemTimeNanoseconds()
{
  return std::chrono::duration_cast<std::chrono::milliseconds>(
    std::chrono::time_point_cast<std::chrono::milliseconds>(
      std::chrono::system_clock::now()
    ).time_since_epoch()
  ).count();
}

// done !!!!!!!!!!
void taskOne(image& layerOne , image& patternOne)
{
  cout << "task one begin\n";
  layerOne.TGAReader("../input/layer1.tga");
  patternOne.TGAReader("../input/pattern1.tga");

  // need to make a copy construtor
  // result

  layerOne.multiply(patternOne); // here may be a problem changing layer 1!!!!!???
  //layerOne changes
  layerOne.TGAWriter("../output/part1.tga");
  // test
  // image* example1 = new image;
  // example1->TGAReader("../examples/EXAMPLE_part1.tga");
  // example1->carbonCopies(layerOne);

}

// done !!!!!!!!!!
void taskTwo(image& layerTwo , image& car)
{
  cout << "task two begin\n";
  // what does top layer and buttom layer mean 
  layerTwo.TGAReader("../input/layer2.tga");
  car.TGAReader("../input/car.tga");
  // need to make a copy construtor
  car.subtract(layerTwo);

// result
  car.TGAWriter("../output/part2.tga");

  // image* example2 = new image;
  // example2->TGAReader("../examples/EXAMPLE_part2.tga");
  // example2->carbonCopies(car);

}


// done !!!!!!!!!!
void taskThree(image& layerOne , image& patternTwo , image& text)
{
  // later problem make sure to have layer1 unchanged!!!!!!!!!!!!!!!!!!
  layerOne.TGAReader("../input/layer1.tga");
  patternTwo.TGAReader("../input/pattern2.tga");
  text.TGAReader("../input/text.tga");
  // 
  layerOne.multiply(patternTwo);
  layerOne.screen(text);

  layerOne.TGAWriter("../output/part3.tga");

  // image* example3 = new image;
  // example3->TGAReader("../examples/EXAMPLE_part3.tga");
  // example3->carbonCopies(layerOne);


}

// done !!!!!!!!!!
void taskFour(image& layerTwo , image& circles , image& patternTwo)
{
  layerTwo.TGAReader("../input/layer2.tga");
  circles.TGAReader("../input/circles.tga");
  patternTwo.TGAReader("../input/pattern2.tga");

  layerTwo.multiply(circles);
  layerTwo.subtract(patternTwo);
  layerTwo.TGAWriter("../output/part4.tga");

  // image* example4 = new image;
  // example4->TGAReader("../examples/EXAMPLE_part4.tga");
  // example4->carbonCopies(layerTwo);


}

// done
void taskFive(image& layerOne , image& patterOne)
{
  layerOne.TGAReader("../input/layer1.tga");
  patterOne.TGAReader("../input/pattern1.tga");
  layerOne.overlay(patterOne);
  layerOne.TGAWriter("../output/part5.tga");

  // image* example5 = new image;
  // example5->TGAReader("../examples/EXAMPLE_part5.tga");
  // example5->carbonCopies(layerOne);

}

// done !!!!!!!!!!
void taskSix(image& car)
{
  car.TGAReader("../input/car.tga");
  unsigned int num = 200;
  car.add(num , "green");
  car.TGAWriter("../output/part6.tga");

  // image* example6 = new image;
  // example6->TGAReader("../examples/EXAMPLE_part6.tga");
  // example6->carbonCopies(car);
}

// done
void taskSeven(image& car)
{
  car.TGAReader("../input/car.tga");
  int scaleOne = 4;
  int scaleTwo = 0;
  car.scaleImageColor(scaleOne , "red");
  car.scaleImageColor(scaleTwo , "blue");
  car.TGAWriter("../output/part7.tga");

  // image* example7 = new image;
  // example7->TGAReader("../examples/EXAMPLE_part7.tga");
  // example7->carbonCopies(car);
}


// done DO NOT UNCOMMENT ALL THREE FOR TESTING AT ONCE YOU WILL GET A CORPUTED LINKED LIST???????
void taskEight(image& carOne , image& carTwo , image& carThree)
{
  carOne.TGAReader("../input/car.tga");
  carTwo.TGAReader("../input/car.tga");
  carThree.TGAReader("../input/car.tga");

  carOne.onlyColor("red");
  carTwo.onlyColor("green");
  carThree.onlyColor("blue");


  carOne.TGAWriter("../output/part8_r.tga");
  carTwo.TGAWriter("../output/part8_g.tga");
  carThree.TGAWriter("../output/part8_b.tga");

  // image* example8r = new image;
  // example8r->TGAReader("../examples/EXAMPLE_part8_r.tga");
  // example8r->carbonCopies(carOne);

  // image* example8g = new image;
  // example8g->TGAReader("../examples/EXAMPLE_part8_g.tga");
  // example8g->carbonCopies(carTwo);

  // image* example8b = new image;
  // example8b->TGAReader("../examples/EXAMPLE_part8_b.tga");
  // example8b->carbonCopies(carThree);

}


void taskNine(image& red , image& green , image& blue)
{
  red.TGAReader("../input/layer_red.tga");
  green.TGAReader("../input/layer_green.tga");
  blue.TGAReader("../input/layer_blue.tga");
  red.combineThree(green , blue);
  red.TGAWriter("../output/part9.tga");

  // image* example9 = new image;
  // example9->TGAReader("../examples/EXAMPLE_part9.tga");
  // example9->carbonCopies(red);

}




void taskTen(image& textTwo)
{
  textTwo.TGAReader("../input/text2.tga");
  textTwo.rotate180();
  textTwo.TGAWriter("../output/part10.tga");

  // image* example10 = new image;
  // example10->TGAReader("../examples/EXAMPLE_part10.tga");
  // example10->carbonCopies(textTwo);


}


// void bonus()
// {

// }



int main()
{

  auto now = systemTimeNanoseconds();

  image* layerOne = new image;
  image* patternOne = new image;
  image* layerTwo = new image;
  image* car = new image;
  image* layerOne2 = new image;
  image* patternTwo = new image;
  image* text = new image;
  image* layerTwo2 = new image;
  image* circles = new image;
  image* patternTwo2 = new image;
  image* layerOne3 = new image;
  image* patternOne2 = new image;
  image* car1 = new image;
  image* car2 = new image;
  image* carOne = new image;
  image* carTwo = new image;
  image* carThree = new image;
  image* red = new image;
  image* green = new image;
  image* blue = new image;
  image* textTwo = new image;

  taskOne(*layerOne , *patternOne);
  taskTwo(*layerTwo , *car);
  taskThree(*layerOne2 , *patternTwo , *text);
  taskFour(*layerTwo2 , *circles , *patternTwo2);
  taskFive(*layerOne3 , *patternOne2);
  taskSix(*car1);
  taskSeven(*car2);
  taskEight(*carOne , *carTwo , *carThree);
  taskNine(*red , *green , *blue);
  taskTen(*textTwo);

  // THERE IS SOMETHING WRONG WITH MY DECSTRUCTOR IT IS DOING SOMETHING WEIRD
  delete layerOne;
  delete patternOne;
  delete layerTwo;
  delete car;
  delete patternTwo;
  delete layerOne2;
  delete text;
  delete layerTwo2;
  delete circles;
  delete patternTwo2;
  delete layerOne3;
  delete patternOne2;
  delete car1;
  delete car2;
  delete carOne;
  delete carTwo;
  delete carThree;
  delete red;
  delete green;
  delete blue;
  delete textTwo;

  layerOne = nullptr;
  patternOne = nullptr;
  layerTwo = nullptr;
  car = nullptr;
  patternTwo = nullptr;
  layerOne2 = nullptr;
  text = nullptr;
  layerTwo2 = nullptr;
  circles = nullptr;
  patternTwo2 = nullptr;
  layerOne3 = nullptr;
  patternOne2 = nullptr;
  car1 = nullptr;
  car2 = nullptr;
  carOne = nullptr;
  carTwo = nullptr;
  carThree = nullptr;
  red = nullptr;
  green = nullptr;
  blue = nullptr;
  textTwo = nullptr;


  cout << "code finished \n";
  auto end = systemTimeNanoseconds();

  double diff = end - now;

  cout << "Time: " << diff << endl;


  return 0;
}