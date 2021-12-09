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
    //vector that holds the frequency of different letters in the input data (alphabetical ordering)
    std::vector<int> letterFrequencies(10);

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

        //for loop counts the frequency of each input letter
        for(int i{0}; i<inputs.size(); i++){
            if(inputs[i].find('a') != std::string::npos){
                letterFrequencies[0] += 1;
            }
            if(inputs[i].find('b') != std::string::npos){
                letterFrequencies[1] += 1;
            }
            if(inputs[i].find('c') != std::string::npos){
                letterFrequencies[2] += 1;
            }
            if(inputs[i].find('d') != std::string::npos){
                letterFrequencies[3] += 1;
            }
            if(inputs[i].find('e') != std::string::npos){
                letterFrequencies[4] += 1;
            }
            if(inputs[i].find('f') != std::string::npos){
                letterFrequencies[5] += 1;
            }
            if(inputs[i].find('g') != std::string::npos){
                letterFrequencies[6] += 1;
            }
        }

        //some letters can now be immediately determined
        
    }
}