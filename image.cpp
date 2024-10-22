#include <iostream> 
#include <vector>
#include <string>
#include <fstream>
using namespace std; 

int main()
{
    // testing this RIGHT NOW NOT ACTAUL CODE
      std::ofstream outFile("example.txt");
    if (outFile.is_open()) {
        outFile << "Hello, this is a test file.\n";
        outFile << "Writing multiple lines of text here...\n";
        outFile.close();
    } else {
        std::cerr << "Unable to open file for writing.\n";
    }

    
    std::ifstream inFile("example.txt");
    std::string line;
    if (inFile.is_open()) {
        while (std::getline(inFile, line)) {
            std::cout << line << '\n';
        }
        inFile.close();
    } else {
        std::cerr << "Unable to open file for reading.\n";
    }
    cout<<"hello world \n";
    return 0;
}
