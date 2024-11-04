#include <iostream> 
#include <vector>
#include <string>
#include <fstream>
#include "image.h"
#include <algorithm> 
using namespace std;







/*

e files in the examples folder can be used to compare against your output. If you load one of those files
and compare it against a file you created, ALL of the data elements should be 100% identical. If even one
component of one pixel is off by the tiniest amount, it is a different image. Every byte/variable of the
header must match, and every pixel must match, exactly.
“I opened both images up and they looked the same” is NOT a valid defense if your images do not match



*/




/*


. Use Multiply blending mode to combine “layer1.tga” (top layer) with “pattern1.tga” (bottom).
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

/*
ou will not be implementing all of those blending modes. For this assignment, you will be implementing
the Multiply, Subtract, Screen, and Overlay blending modes. In addition, you should be able to modify
the individual channels by adding a value to them (such as adding 20 to the red channel, or “adding” -20
to the blue channel), or by scaling them (such as scaling the green channel by 50%). The specific operations
you will have to perform are listed below, under the heading Tasks

*/


// When you WRITE IT OVER RIGHTS THE FILES SETTING IT TO 0 !!!!!!!!!!!!!!
// READING AND WRIGHTING
void image::TGAReader(const string fileName) {

    fstream fileStream(fileName , ios::in | ios::binary);


    if (header == nullptr) {

        header = new Header;
    }

    if (!fileStream.is_open()) throw invalid_argument("No file");

    fileStream.read(&header->idLength , sizeof(header->idLength));
    fileStream.read(&header->colorMapType , sizeof(header->colorMapType));
    fileStream.read(&header->dataTypeCode , sizeof(header->dataTypeCode));
    fileStream.read((char*)&header->colorMapOrigin , sizeof(header->colorMapOrigin));
    fileStream.read((char*)&header->colorMapLength , sizeof(header->colorMapLength));
    fileStream.read(&header->colorMapDepth , sizeof(header->colorMapDepth));
    fileStream.read((char*)&header->xOrigin , sizeof(header->xOrigin));
    fileStream.read((char*)&header->yOrigin , sizeof(header->yOrigin));
    fileStream.read((char*)&header->width , sizeof(header->width));
    fileStream.read((char*)&header->height , sizeof(header->height));
    fileStream.read(&header->bitsPerPixel , sizeof(header->bitsPerPixel));
    fileStream.read(&header->imageDescriptor , sizeof(header->imageDescriptor));

    // pixels

    /*
     to store the TGA file? You would need...
• The header. 18 bytes worth of data (even if you really only care about 4 bytes – 2 bytes for width,
2 for height). You will need all 18 bytes of this header data to properly write a .TGA file.
• The pixels. A pixel is 3 values: R, G, and B, and each of those is a number from 0-255 (an unsigned
char fits this perfectly). You will need a way to store a lot of them; a medium-sized image that’s
512x512 contains 262,144 pixels

    */
    fileStream.seekg(18 , ios::beg);

    this->pixels = new char[header->height * header->width * 3];

    // Read pixel data
    fileStream.read(this->pixels , header->height * header->width * 3);


    //prints out the image for testing
    // for (int i = 0; i < 100; i++) {
    //     unsigned char red = pixels[i * 3];
    //     unsigned char green = pixels[i * 3 + 1];
    //     unsigned char blue = pixels[i * 3 + 2];
    //     cout << "Pixel " << i << ": R=" << (int)red << " G=" << (int)green << " B=" << (int)blue << endl;
    // }

    fileStream.close();

}


// When you WRITE IT OVER RIGHTS THE FILES SETTING IT TO 0 !!!!!!!!!!!!!!
void image::TGAWriter(string outPutFile)
{
    // fstream fileStream(outPutFile , ios::binary | ios::out);

    // fileStream.write(&header->idLength , sizeof(header->idLength));
    // fileStream.write(&header->colorMapType , sizeof(header->colorMapType));
    // fileStream.write(&header->dataTypeCode , sizeof(header->dataTypeCode));
    // fileStream.write((char*)&header->colorMapOrigin , sizeof(header->colorMapOrigin));
    // fileStream.write((char*)&header->colorMapLength , sizeof(header->colorMapLength));
    // fileStream.write(&header->colorMapDepth , sizeof(header->colorMapDepth));
    // fileStream.write((char*)&header->xOrigin , sizeof(header->xOrigin));
    // fileStream.write((char*)&header->yOrigin , sizeof(header->yOrigin));
    // fileStream.write((char*)&header->width , sizeof(header->width));
    // fileStream.write((char*)&header->height , sizeof(header->height));
    // fileStream.write(&header->bitsPerPixel , sizeof(header->bitsPerPixel));
    // fileStream.write(&header->imageDescriptor , sizeof(header->imageDescriptor));


     //  fileStream.write(this->pixels , header->height * header->width * 3);
    cout << "I RAN????????????\n";


    //fileStream.close();

}



// Header things now !!!!!!!!!!!!!!!!!!!!!




image::Header image::getHeader() const
{
    return *header;
}

void image::setHeader(Header& header)
{
    char idLength = header.idLength;
    char colorMapType = header.colorMapType;
    char dataTypeCode = header.dataTypeCode;
    short colorMapOrigin = header.colorMapOrigin;
    short colorMapLength = header.colorMapLength;
    char colorMapDepth = header.colorMapDepth;
    short xOrigin = header.xOrigin;
    short yOrigin = header.yOrigin;
    short width = header.width;
    short height = header.height;
    char bitsPerPixel = header.bitsPerPixel;
    char imageDescriptor = header.imageDescriptor;
}

void image::printHeader(const Header& header)
{
    cout << "The ID Length is: " << (char)header.idLength << endl;
    cout << "The Color Map Type is: " << (char)header.colorMapDepth << endl;
    cout << "The Data Type Code is: " << (char)header.dataTypeCode << endl;
    cout << "The Color Map Origin is: " << (short)header.colorMapOrigin << endl;
    cout << "The Color Map Length is: " << (short)header.colorMapLength << endl;
    cout << "The Color Map Depth is: " << (char)header.colorMapDepth << endl;
    cout << "The X-Origin is: " << (short)header.xOrigin << endl;
    cout << "The Y-Origin is: " << (short)header.yOrigin << endl;
    cout << "The Width is: " << (short)header.width << endl;
    cout << "The Height is: " << (short)header.height << endl;
    cout << "The Bits Per Pixel is: " << (char)header.bitsPerPixel << endl;
    cout << "The Image Descriptor is: " << (char)header.imageDescriptor << endl;
}



//pixel manipulation !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


// IDK IF I NEED 



void image::multiply(const image& diffImage)
{
    if (header->width != diffImage.header->width || header->height != diffImage.header->height) {
        throw invalid_argument("ERROR!!!!!! This doesn't work");
    }
    size_t numPixels = header->width * header->height * 3;
    for (size_t i = 0; i < numPixels; i++)
    {
        pixels[i] = static_cast<unsigned char>((pixels[i] / 255.0 * diffImage.pixels[i] / 255.0) * 255);
    }

     // this checks for core dumps
    cout << " done multipling ";
}




void image::scaleImageColor(int scalar , const string color)
{
    // CORE DUMPS
    //    size_t numPixels = header->width * header->height * 3;


    size_t numPixels = header->width * header->height; // works like this ???????????? why 

    for (size_t i = 0; i < numPixels; i++) {
        if (color == "red") {
           // cout << "It works for i = R " << i << endl;
            pixels[i * 3] = min(255 , max(0 , static_cast<int>(static_cast<unsigned char>(pixels[i * 3])) * scalar));
        }
        else if (color == "green") {
           // cout << "It works for i = G" << i << endl;
            pixels[i * 3 + 1] = min(255 , max(0 , static_cast<int>(static_cast<unsigned char>(pixels[i * 3 + 1])) * scalar));
        }
        else if (color == "blue") {
           // cout << "It works for i = B " << i << endl;
            pixels[i * 3 + 2] = min(255 , max(0 , static_cast<int>(static_cast<unsigned char>(pixels[i * 3 + 2])) * scalar));
        }
    }
    cout << "done scalling \n";
}




void image::add(int num , const string& color)
{
    size_t numPixels = header->width * header->height; // works like this ???????????? why 
    /// maybe too tired idk  I get themultiplications we trying to do that strong proff by induciton struff
    // ya know 


   // NO CORE DUMPS BUT NEED TO CHECK IF IT is ACTUALLY RIGHT
    //size_t numPixels = header->width * header->height * 3;

   // cout << "It number of pixels" << numPixels << endl;
    for (size_t i = 0; i < numPixels; i++) {
        if (color == "red") {
            //cout << "It works for i = R " << i << endl;
            pixels[i * 3] = min(255 , max(0 , static_cast<int>(static_cast<unsigned char>(pixels[i * 3])) + num));
        }
        else if (color == "green") {
            //cout << "It works for i = G" << i << endl;
            pixels[i * 3 + 1] = min(255 , max(0 , static_cast<int>(static_cast<unsigned char>(pixels[i * 3 + 1])) + num));
        }
        else if (color == "blue") {
            //cout << "It works for i = B " << i << endl;
            pixels[i * 3 + 2] = min(255 , max(0 , static_cast<int>(static_cast<unsigned char>(pixels[i * 3 + 2])) + num));
        }
    }

    // this checks for core dumps
    cout << " done adding \n";
}


void image::subtract(const image& diffImage) {

    if (header->width != diffImage.header->width || header->height != diffImage.header->height) {
        throw invalid_argument("ERROR!!!!!! This doesn't work");
    }

    size_t numPixels = header->width * header->height * 3;
    for (size_t i = 0; i < numPixels; i++) {
        pixels[i] = max(0 , pixels[i] - diffImage.pixels[i]);
    }

    // this checks for core dumps
    cout << " done  subtracting\n";
}

void image::rotate180()
{
       // NO CORE DUMPS BUT NEED TO CHECK IF IT is ACTUALLY RIGHT
    int rowSize = header->width * 3;
    int halfHeight = header->height / 2;

    for (int i = 0; i < halfHeight; i++) {
        int topRow = i * rowSize;
        int bottomRow = (header->height - i - 1) * rowSize;

        for (int j = 0; j < rowSize; j++) {
            swap(pixels[topRow + j] , pixels[bottomRow + j]);
        }
    }

    // this checks for core dumps
    cout << " rotating done \n";


}

void image::printThatImage()
{
    // probaly a num ptr if it doesn't work
    if (!header) {
        cerr << "Header not initialized!????" << endl;
        return;
    }

    int allPixles = header->width * header->height * 3;
    for (int i = 0; i < 100; i++) {
        unsigned char red = pixels[i * 3];
        unsigned char green = pixels[i * 3 + 1];
        unsigned char blue = pixels[i * 3 + 2];
        cout << "Pixel " << i << ": R=" << (int)red << " G=" << (int)green << " B=" << (int)blue << endl;
    }

}



void image::carbonCopies(const image& diffImage)
{
    image::Header diffHeader = diffImage.getHeader();
    image::Header thisHeader = this->getHeader();

    if (thisHeader.width != diffHeader.width || thisHeader.height != diffHeader.height) {
        throw invalid_argument("ERROR!!!!!! This doesn't work OH NO!!!!!!!");
    }

    size_t numPixels = thisHeader.width * thisHeader.height;
    long long int tester = 0;

    try
    {
        for (size_t i = 0; i < numPixels; i++) {
            bool same = true;
            for (int j = 0; j < 3; j++)
            {
                if (pixels[i * 3 + j] != diffImage.pixels[i * 3 + j])
                {
                    same = false;
                    break;
                }
            }

            if (same) {
                cout << "Pixel " << i << " is the same in both images." << endl;
            }
            else {
                cout << "Pixel " << i << " is different in the images." << endl;
            }

            tester++;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << " NO!! at: " << tester << " NOO!!!!! \n";
    }

    cout << "done testing\n";
}


