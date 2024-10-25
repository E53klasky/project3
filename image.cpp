#include <iostream> 
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include "structHeader.h"
using namespace std; 
// NOTES!!!!!!!!!!!!!!!!!!!!!!!!!!!
// EXAMPLES HAS EVERYTHING TO LOOK AT
// ROUNDING WITH FLOATS 
    // To do that, simply add 0.5f to the final value before
    // assigning back to an unsigned char variable


// TODO!!!!!!!!!!!!!!!: 
/*
Use Multiply blending mode to combine “layer1.tga” (top layer) with “pattern1.tga” (bottom).
2. Use the Subtract blending mode to combine “layer2.tga” (top layer) with “car.tga” (bottom layer).
This mode subtracts the top layer from the bottom layer.
3. Use the Multiply blending mode to combine “layer1.tga” with “pattern2.tga”, and store the
results temporarily. Load the image “text.tga” and, using that as the top layer, combine it with
the previous results of layer1/pattern2 using the Screen blending mode.
4. Multiply “layer2.tga” with “circles.tga”, and store it. Load “pattern2.tga” and, using that as the
top layer, combine it with the previous result using the Subtract blending mode.
5. Combine “layer1.tga” (as the top layer) with “pattern1.tga” using the Overlay blending mode.
6. Load “car.tga” and add 200 to the green channel.
7. Load “car.tga” and scale (multiply) the red channel by 4, and the blue channel by 0. This will
increase the intensity of any red in the image, while negating any blue it may have.
8. Load “car.tga” and write each channel to a separate file: the red channel should be “part8_r.tga”,
the green channel should be “part8_g.tga”, and the blue channel should be “part8_b.tga”
9. Load “layer_red.tga”, “layer_green.tga” and “layer_blue.tga”, and combine the three files into
one file. The data from “layer_red.tga” is the red channel of the new image, layer_green is
green, and layer_blue is blue.
10. Load “text2.tga”, and rotate it 180 degrees, flipping it upside down. This is easier than you think!
Try diagramming the data of an image (such as earlier in this document). What would the data
look like if you flipped it? Now, how to write some code to accomplish that...?

*/

vector<unsigned char*> Multiply(vector<unsigned char*>& data)
{  
    // Convert 0-255 value to a 0-1 value (dividing the original by the maximum), perform the calculation
    // with 0-1 values, and then convert back to the original range afterward (multiplying the 0-1 range by the
    // maximum). 
    // TRY THIS TO KEEP IT AS UNSIGNED CHAR OTHERWISE do it with an int or float then go back to unsigned char.

    vector<unsigned char*> result; 
    for (size_t i = 0; i < data.size(); i++) {
       
        int temp = static_cast<int>(*data[i]) * 2;  // testing 2 for RN
        if(temp > 255) temp = 255;
         unsigned char* newValue = new unsigned char(static_cast<unsigned char>(temp));
        result.push_back(newValue);
    }

    cout << "Multiply: Completed" << endl;
    return result;
}

vector<unsigned char*> Add(vector<unsigned char>& data)
{  // cast to int then back to unisigned char
    // cap if over 255 MAX??
    // MAKE SURE YOU ROUND CORRECTLY
  
   vector<unsigned char*> result;
    for (size_t i = 0; i < data.size(); i++) {

        int temp = (int)data[i] + 10; // testing 10 RN
        if(temp > 255) temp = 255; 
        unsigned char* newValue = new unsigned char(static_cast<unsigned char>(temp));
        result.push_back(newValue);
    }

    cout << "Add: Completed" << endl;
    return result;

}


vector<unsigned char*> Subtract(vector<unsigned char>& data)
    
{  // cast to int then back to unisigned char
    // cap if over 0 MIN????
    // MAKE SURE YOU ROUND CORRECTLY
    
     vector<unsigned char*> result;
    for (size_t i = 0; i < data.size(); i++) {
       
        int temp = (int)data[i] - 10; // testing 10 RN
        if(temp < 0) temp = 0; 
        unsigned char* newValue = new unsigned char(static_cast<unsigned char>(temp));
        result.push_back(newValue);
    }

    cout << "Subtract: Completed" << endl;
    return result;

}


int main()
{
    //Multiply, Subtract, Screen, and Overlay blending modes. I

    /*
    have to go down one directory then go to the file path!!!!!!!!!!
    car.tga                         layer_green.tga:Zone.Identifier
car.tga:Zone.Identifier         layer_red.tga
circles.tga                     layer_red.tga:Zone.Identifier
circles.tga:Zone.Identifier     pattern1.tga
layer1.tga                      pattern1.tga:Zone.Identifier
layer1.tga:Zone.Identifier      pattern2.tga
layer2.tga                      pattern2.tga:Zone.Identifier
layer2.tga:Zone.Identifier      text.tga
layer_blue.tga                  text.tga:Zone.Identifier
layer_blue.tga:Zone.Identifier  text2.tga
layer_green.tga                 text2.tga:Zone.Identifier
    */
    
    // file stream for ins 
    fstream fileStream("../input/circles.tga", ios::in | ios::binary);

    Header* header = new Header;


     if (!fileStream) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    
   
    // cast to character
    //  get(destination, size, delimiter
    // mine is not a pointer so do .

    fileStream.read(&header->idLength, sizeof(header->idLength));
    fileStream.read(&header->colorMapType, sizeof(header->colorMapType));
    fileStream.read(&header->dataTypeCode, sizeof(header->dataTypeCode));
    fileStream.read((char *) &header->colorMapOrigin, sizeof(header->colorMapOrigin));
    fileStream.read((char *) &header->colorMapLength, sizeof(header->colorMapLength));
    fileStream.read( &header->colorMapDepth, sizeof(header->colorMapDepth));
    fileStream.read((char *) &header->xOrigin, sizeof(header->xOrigin));
    fileStream.read((char *) &header->yOrigin, sizeof(header->yOrigin));
    fileStream.read((char *) &header->width, sizeof(header->width));
    fileStream.read((char *) &header->height, sizeof(header->height));
    fileStream.read(&header->bitsPerPixel, sizeof(header->bitsPerPixel));
    fileStream.read(&header->imageDescriptor,sizeof(header->imageDescriptor));

    printHead(*header);
    delete header;
    header = nullptr;




    // DO IT AGAIN FOR OUTS  fstream fileStream("../input/circles.tga", ios::in | ios::binary);
    fileStream.open("../output");
    
    //vector<unsigned char> data(istreambuf_iterator<char>(fileStream), {});
    // // this views the data in the terminal right now!!!!!!!!
    // for (size_t i = 0; i < data.size() && i <100; i++)
    // {
    //     cout<< hex << uppercase<<int(data[i])<<"";
    //     if((i+1) % 10 == 0) cout <<endl;
    // }
    // cout << dec;
    
  
  
    return 0;
}