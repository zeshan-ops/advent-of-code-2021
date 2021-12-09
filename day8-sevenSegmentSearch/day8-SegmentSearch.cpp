#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

int main(){
    std::string fileName;
    std::cout << "Enter input filename: " << std::endl;
    std::cin >> fileName;

    std::ifstream inputFile(fileName);

    std::string singleLine;
    int counter{0};
    while(getline(inputFile, singleLine)){
        std::stringstream ss(singleLine);
        std::string tenSignals;
        getline(ss,tenSignals, '|');
        std::string outputNumbers;
        getline(ss,outputNumbers);
        std::stringstream ss2(outputNumbers);
        std::string individualNumbers;
        while(getline(ss2,individualNumbers,' ')){
            int elements = individualNumbers.length();
            if(elements == 7 ||
               elements == 2 ||
               elements == 3 ||
               elements == 4){
                   counter += 1;
               }
        }
    }

    std::cout << "Total Count: " << counter << std::endl;
    return 0;
}