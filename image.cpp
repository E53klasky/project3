#include <iostream> 
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include "structHeader.h"
using namespace std; 



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
    
    fstream fileStream("../input/circles.tga", ios::in | ios::binary);

    Header header;


     if (!fileStream) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }
    vector<unsigned char> buffer(istreambuf_iterator<char>(fileStream), {});
    
    fileStream.close();

    header.idLength = buffer[0];
    header.colorMapType = buffer[1];
    header.dataTypeCode = buffer[2];
    header.colorMapOrigin = buffer[3] + 1;
    header.colorMapLength = buffer[5] + 1;
    header.colorMapDepth = buffer[7];
    header.xOrigin = buffer[8] + 1;
    header.yOrigin = buffer[10] +1;
    header.width = buffer[12] +1;
    header.height = buffer[14] +1;
    header.bitsPerPixel = buffer[16];
    header.imageDescriptor = buffer[17];

    // this views the data in the terminal right now!!!!!!!!
    for (size_t i = 0; i < buffer.size() && i <100; i++)
    {
        cout<< hex << uppercase<<int(buffer[i])<<"";
        if((i+1) % 10 == 0) cout <<endl;
    }
    
    cout << dec;



    
    return 0;
}