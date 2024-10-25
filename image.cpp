#include <iostream> 
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include "structHeader.h"
using namespace std; 

// void multiple(vector<unsigned char> data&)
// {  
//     cout<<"hi";

// }


int main()
{

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
    
  
    delete header;
    return 0;
}