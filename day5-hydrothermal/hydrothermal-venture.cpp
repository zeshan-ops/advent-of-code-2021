#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

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

/*
Main program
*/
int main(int argc, char * argv[]){
    std::string inputFilename;

    //dealing with command line arguments first
    if(cmdOptionIndex(argc,argv,"-h")!=0){
        std::cout << "Help text not implemented" << std::endl;
    }
    if(cmdOptionIndex(argc,argv,"-i")!=0){
        inputFilename = argv[cmdOptionIndex(argc,argv,"-i")+1];
    }
    
    return 0;
}