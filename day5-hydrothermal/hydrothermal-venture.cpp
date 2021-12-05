#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>

/*
Soln to Day 5 of AoC2021 - Hydrothermal Venture
*/

/*
parsing command line inputs
*/

//finds argv index for a cmd line otion
int cmdOptionIndex(int& argc, char* argv[], std::string option){
    int optionIndex{0};
    for(int i{0}; i<argc; i++){
        if((std::string)argv[i] == option){
            optionIndex = i;
            break;
        }
    }
    return optionIndex;
}

//converts a single line of input into x1y1x2y2 in a vector
std::vector<int> lineConverter(std::string& line){
    std::vector<int> twoPoints;
    std::string firstCoords;
    std::string secondCoords;
    int x1,y1,x2,y2;

    firstCoords = line.substr(0,line.find(" -> "));

    std::cout << firstCoords << std::endl;

    secondCoords = line.substr(line.find(" -> ")+4);

    std::cout << secondCoords << std::endl;

    x1 = stoi(firstCoords.substr(0,firstCoords.find(',')));
    y1 = stoi(firstCoords.substr(firstCoords.find(',')+1));

    x2 = stoi(secondCoords.substr(0,secondCoords.find(',')));
    y2 = stoi(secondCoords.substr(secondCoords.find(',')+1));

    twoPoints.push_back(x1);
    twoPoints.push_back(y1);
    twoPoints.push_back(x2);
    twoPoints.push_back(y2);

    return twoPoints;
}

/*
Main program
*/
int main(int argc, char * argv[]){
    int dimension;
    std::string inputFilename;

    //dealing with command line arguments first
    if(cmdOptionIndex(argc,argv,"-h")!=0){
        std::cout << "Help text not implemented" << std::endl;
    }
    if(cmdOptionIndex(argc,argv,"-i")!=0){
        inputFilename = argv[cmdOptionIndex(argc,argv,"-i")+1];
    }
    else{
        std::cout << "Error. No input file given" << std::endl;
        return 1;
    }
    if(cmdOptionIndex(argc,argv,"-d")!=0){
        dimension = (int)argv[cmdOptionIndex(argc,argv,"-d")+1];
    }
    else{
        std::cout << "Error. No grid dimension given." << std::endl;
        return 1;
    }

    //reading input file
    std::ifstream inputFile(inputFilename);
    if(inputFile){
        std::cout << "File opened successfully\n";
    } 
    else{std::cout << "error opening file\n";}

    //intialising overlap vector
    std::vector<std::vector<int>> overLaps(dimension,
                                           std::vector<int>(dimension));

    
    return 0;

}