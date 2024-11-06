#include <iostream> 
#include <vector>
#include <string>
#include <fstream>
#include "image.h"
#include <algorithm> 
using namespace std;


// When you WRITE IT OVER RIGHTS THE FILES SETTING IT TO 0 !!!!!!!!!!!!!!
// --------READING AND WRIGHTING-------------------------------------

void image::TGAReader(const string fileName) {


    fstream fileStream(fileName , ios_base::in | ios::binary);


    if (header == nullptr) {

        header = new Header;
    }

    if (!fileStream.is_open()) throw invalid_argument("No file?????");

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


        // if (eof) is true then you are at the end of the file

    this->pixels = new char[header->height * header->width * 3];

// Read pixel data
    fileStream.read(this->pixels , header->height * header->width * 3);


    //prints out the image for testing
    cout << "READING IN\n";
    // for (int i = 0; i < 10; i++) {
    //     unsigned char blue = pixels[i * 3];
    //     unsigned char green = pixels[i * 3 + 1];
    //     unsigned char red = pixels[i * 3 + 2];
    //     cout << "Pixel " << i << ": B=" << (int)blue << " G=" << (int)green << " R=" << (int)red << endl;
    // }

    fileStream.close();

}


// When you WRITE IT OVER RIGHTS THE FILES SETTING IT TO 0 !!!!!!!!!!!!!!
void image::TGAWriter(string outPutFile)
{

    fstream fileStream(outPutFile , ios_base::out | ios_base::binary);


    fileStream.write(&header->idLength , sizeof(header->idLength));
    fileStream.write(&header->colorMapType , sizeof(header->colorMapType));
    fileStream.write(&header->dataTypeCode , sizeof(header->dataTypeCode));
    fileStream.write((char*)&header->colorMapOrigin , sizeof(header->colorMapOrigin));
    fileStream.write((char*)&header->colorMapLength , sizeof(header->colorMapLength));
    fileStream.write(&header->colorMapDepth , sizeof(header->colorMapDepth));
    fileStream.write((char*)&header->xOrigin , sizeof(header->xOrigin));
    fileStream.write((char*)&header->yOrigin , sizeof(header->yOrigin));
    fileStream.write((char*)&header->width , sizeof(header->width));
    fileStream.write((char*)&header->height , sizeof(header->height));
    fileStream.write(&header->bitsPerPixel , sizeof(header->bitsPerPixel));
    fileStream.write(&header->imageDescriptor , sizeof(header->imageDescriptor));


    fileStream.write(this->pixels , header->height * header->width * 3);
    cout << "Wrote to disk????????????\n";
    cout << "the first 10 pixles: \n";
    for (int i = 0; i < 10; i++) {
        unsigned char blue = pixels[i * 3];
        unsigned char green = pixels[i * 3 + 1];
        unsigned char red = pixels[i * 3 + 2];
        cout << "Pixel " << i << ": B=" << (int)blue << " G=" << (int)green << " R=" << (int)red << endl;
    }


    fileStream.close();

}



// ------------- Header ----------------------------


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


unsigned int image::convertCharToInt(unsigned char ltr)
{
    return (unsigned int)(ltr - '\0');
}

unsigned char image::convertIntToChar(unsigned int num)
{
    return (unsigned char)(num + '\0');
}



//------------------------pixel manipulation ---------------------------

// works with task2!!!!!!!!!!!!!!!
void image::multiply(const image& diffImage)
{
    if (header->width != diffImage.header->width || header->height != diffImage.header->height) {
        throw invalid_argument("ERROR!!!!!! This doesn't work");
    }

    size_t numPixels = header->width * header->height * 3;
    for (size_t i = 0; i < numPixels; i++)
    {
        //cout << "layer1 fisrt pixel: " << static_cast<int> (pixels[i]) << " pattern1 first pixel " << static_cast<int> (diffImage.pixels[i]) << endl;
        float thisPix = static_cast<float>(convertCharToInt(pixels[i])) / 255.0f;
        float diffPix = static_cast<float> (convertCharToInt(diffImage.pixels[i])) / 255.0f;
        //cout << "float val of pix" << thisPix << endl;
       // cout << "float val of diffpix" << diffPix << endl;

        float result = 0.5 + ((thisPix * diffPix) * 255.0f);
        unsigned int newResult = static_cast<int> (result);
        pixels[i] = convertIntToChar(newResult);

    }

    cout << " done multiplying \n";
}


// BGR
// QUESTIONS WIth CASTING THIS ONE!!!!!!!!!
void image::scaleImageColor(int scalar , const string color)
{
    //    size_t numPixels = header->width * header->height * 3;

    size_t numPixels = header->width * header->height; // works like this ???????????? why 

    for (size_t i = 0; i < numPixels; i++) {
        if (color == "blue") {
           // cout << "It works for i = B " << i << endl;
            unsigned int blue = min(255 , max(0 , (int)convertCharToInt(pixels[i * 3]) * (int)scalar));
            pixels[i * 3] = convertIntToChar(blue);
        }
        else if (color == "green") {
           // cout << "It works for i = G" << i << endl;
            unsigned int green = min(255 , max(0 , (int)convertCharToInt(pixels[i * 3 + 1]) * (int)scalar));
            pixels[i * 3 + 1] = convertIntToChar(green);
        }
        else if (color == "red") {
           // cout << "It works for i = R " << i << endl;
            unsigned int red = min(255 , max(0 , (int)convertCharToInt(pixels[i * 3 + 2]) * (int)scalar));
            pixels[i * 3 + 2] = convertIntToChar(red);
        }
    }
    cout << "done scalling \n";
}



// BGR 
void image::add(int num , const string& color)
{
    size_t numPixels = header->width * header->height;

    //size_t numPixels = header->width * header->height * 3;

   // cout << "It number of pixels" << numPixels << endl;
    for (size_t i = 0; i < numPixels; i++) {
        if (color == "blue") {
            //cout << "It works for i = B " << i << endl;
            unsigned int blue = min(255 , max(0 , (int)convertCharToInt(pixels[i * 3]) + (int)num));
            pixels[i * 3] = convertIntToChar(blue);
        }
        else if (color == "green") {
            //cout << "It works for i = G" << i << endl;
            unsigned int green = min(255 , max(0 , (int)convertCharToInt(pixels[i * 3 + 1]) + (int)num));
            pixels[i * 3 + 1] = convertIntToChar(green);
        }
        else if (color == "red") {
            //cout << "It works for i = R " << i << endl;
            unsigned int red = min(255 , max(0 , (int)convertCharToInt(pixels[i * 3 + 2]) + (int)num));
            pixels[i * 3 + 2] = convertIntToChar(red);
        }
    }

    // this checks for core dumps
    cout << " done adding \n";
}


void image::subtract(image& diffImage) {

    // times 3 when literally all pixels
    if (header->width != diffImage.header->width || header->height != diffImage.header->height) {
        throw invalid_argument("ERROR!!!!!! This doesn't work");
    }
    cout << "start subtracting\n";

    size_t numPixels = header->width * header->height * 3;
    for (size_t i = 0; i < numPixels; i++) {
       // cout << "cars fisrt pixel: " << static_cast<int> pixels[i] << " layerTwos first pixel " << static_cast<int> diffImage.pixels[i] << endl;
        int myPix = convertCharToInt(pixels[i]);
        int diffPix = convertCharToInt(diffImage.pixels[i]);
        int test = (myPix - diffPix);
        //cout << "val: " << test << " i: " << i << endl;

        int diff = myPix - diffPix;
        int vals = max(0 , diff);
       // cout << "vals: " << vals << " i: " << i << endl;
        pixels[i] = convertIntToChar(vals);

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


// this one
void image::overlay(const image& diffImage)
{

    image::Header diffHeader = diffImage.getHeader();
    image::Header thisHeader = this->getHeader();


    if (thisHeader.width != diffHeader.width || thisHeader.height != diffHeader.height) {
        throw invalid_argument("ERROR!!!!!! This doesn't work OH NO!!!!!!!");
    }

    size_t numPixels = thisHeader.width * thisHeader.height * 3;
    for (size_t i = 0; i < numPixels; i++)
    {

        if (convertIntToChar(convertCharToInt(pixels[i]) + convertCharToInt(diffImage.pixels[i])) > 255) {
            pixels[i] = 255;
        }

        else {
            pixels[i] = convertIntToChar(convertCharToInt(pixels[i]) + convertCharToInt(diffImage.pixels[i]));
        }

    }

    cout << "DONE overlaying \n";

}

// need screen and combine
void image::screen(const image& diffImage)
{
    image::Header diffHeader = diffImage.getHeader();
    image::Header thisHeader = this->getHeader();


    if (thisHeader.width != diffHeader.width || thisHeader.height != diffHeader.height) {
        throw invalid_argument("ERROR!!!!!! This doesn't work OH NO!!!!!!!");
    }
    size_t numPixels = thisHeader.width * thisHeader.height;

    for (size_t i = 0; i < numPixels; i++)
    {

        pixels[i] = static_cast<unsigned char>(0.5 + (255 - ((static_cast<float>(255 - convertCharToInt(pixels[i])) * static_cast<float>(255 - convertCharToInt(diffImage.pixels[i]))) / 255)));
    }

    cout << "DONE WITH SCREENING\n";
}


// I may have trouble with this one!!!!!!!
void image::combineThree(const image& green , const image& blue)
{
    image::Header redHeader = this->getHeader();
    image::Header greenHeader = green.getHeader();
    image::Header blueHeader = blue.getHeader();

    if (redHeader.width != greenHeader.width || redHeader.height != greenHeader.height ||
        redHeader.width != blueHeader.width || redHeader.height != blueHeader.height) {
        throw std::invalid_argument("ERROR: Images do not have the same diminestions");
    }
    size_t numPixels = redHeader.width * redHeader.height;
    for (size_t i = 0; i < numPixels; i++)
    {
        pixels[i * 3 + 1] = green.pixels[i * 3 + 1];
        pixels[i * 3 + 2] = blue.pixels[i * 3 + 2];
    }


    cout << "DONE WITH COMBINING \n";

}

// BGR NOT RGB
void image::onlyColor(const std::string& color)
{
    size_t numPixels = header->width * header->height;
    for (size_t i = 0; i < numPixels; i++)
    {
        if (color == "blue") {

            pixels[i * 3 + 1] = pixels[i * 3];
            pixels[i * 3 + 2] = pixels[i * 3];
        }
        else if (color == "green") {

            pixels[i * 3] = pixels[i * 3 + 1];
            pixels[i * 3 + 2] = pixels[i * 3 + 1];
        }
        else if (color == "red") {

            pixels[i * 3] = pixels[i * 3 + 2];
            pixels[i * 3 + 1] = pixels[i * 3 + 2];
        }
    }

    std::cout << "DONE with only color\n";
}



// -----------------------testing now-----------------------------
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
        throw std::invalid_argument("ERROR!!!!!! This doesn't work OH NO!!!!!!!");
    }

    size_t numPixels = thisHeader.width * thisHeader.height;
    long long int tester = 0;

    try
    {
        for (size_t i = 0; i < numPixels; i++)
        {
            bool same = true;
            for (int j = 0; j < 3; j++)
            {
                if (pixels[i * 3 + j] != diffImage.pixels[i * 3 + j])
                {
                    cout << static_cast<int>(pixels[i * 3 + j]) << endl;
                    cout << static_cast<int>(diffImage.pixels[i * 3 + j]) << endl;
                    same = false;
                    break;
                }
            }

            if (same) {
                // uncomment when testing a task for that saticfation of seeing all correct
                cout << "Pixel " << i << " is the same in both images." << endl;
            }
            else {
                cout << "Pixel " << i << " is different in the images." << endl;
                cout << "Example pixle value is " << convertCharToInt(diffImage.pixels[i]) << endl;
                cout << "Your pixle value is " << convertCharToInt(pixels[i]) << endl;
                break;
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


// -------------copy constructor --------------------------

 // copy constuctor
    // image(const image& diffImage);
    // {


    //     newImage = dif
    // }


// SOMETHING LIKE THIS
// image operator = (const image& diffImage);
// {
//     this->header = diffImage.header;
//     this->pixels = diffImage.pixels;
//     return this*;
// }




