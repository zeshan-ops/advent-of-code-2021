#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

int main(){
    //segments of the display
    std::string a,b,c,d,e,f,g;
    //how each number is formed on the display (each element is a string of segments)
    std::vector<std::string> numbers;
    //vector that holds the frequency of different letters in the input data
    std::vector<int> letterFrequencies;

    //strings that hold each of the ten input strings
    std::vector<std::string> inputs;

    //reading the input file
    std::string fileName;
    std::cout << "Enter Input File Name: ";
    std::cin >> fileName;
    std::ifstream inputFile(fileName);


    std::string row; //stores individual row of input file
    while(getline(inputFile, row)){
        std::stringstream ss(row); //used so we can break up a single row
        std::string tenInputs; //stores the ten input strings
        std::string outputs; // stores the outputs of each line
        getline(ss,tenInputs,'|');
        ss >> outputs; //row has now been split into tenInputs and outputs
        std::stringstream ss2(tenInputs);
        std::string singleInput;
        while(getline(ss2,singleInput, ' ')){
            inputs.push_back(singleInput); //each individual input is now stores as an entry in the inputs vector
        }
        for(int i{0}; i<inputs.size(); i++){
            //code to update letterFrequencies
        }
    }
}