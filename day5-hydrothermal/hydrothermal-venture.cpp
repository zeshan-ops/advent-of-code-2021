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

/*
Program Specific Functions
*/

//converts a single line of input into x1y1x2y2 in a vector
std::vector<int> lineConverter(std::string& line){
    std::vector<int> twoPoints;
    std::string firstCoords;
    std::string secondCoords;
    int x1,y1,x2,y2;

    firstCoords = line.substr(0,line.find(" -> "));

    secondCoords = line.substr(line.find(" -> ")+4);

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

//checks if two points form a vertical or horizontal line
std::string lineChecker(int x1, int y1, int x2, int y2){
    if(x1==x2){
        return "vertical";
    }
    else if(y1==y2){
        return "horizontal";
    }
    else{
        return "nope";
    }
}

//updates which points occupy the horziontal/vertical lines - part1 specific
void overlapsUpdater(std::string orientation, int x1, int y1, int x2, int y2, std::vector<std::vector<int>>& overlaps){
    int startX, endX, startY, endY;
    if(orientation == "horizontal"){
        if(x1<x2){
            startX = x1;
            endX = x2;
            startY = y1;
            endY = y2;
        }
        else{
            startX = x2;
            endX = x1;
            startY = y2;
            endY = y1;
        }
        for(int i{startX}; i<endX+1;i++){
            overlaps[i][startY] += 1;
        }
    }
    else if(orientation == "vertical"){
        if(y1<y2){
            startX = x1;
            endX = x2;
            startY = y1;
            endY = y2;
        }
        else{
            startX = x2;
            endX = x1;
            startY = y2;
            endY = y1;
        }
        for(int i{startY}; i<endY+1;i++){
            overlaps[startX][i] += 1;
        }
    }

}

//counts the number of points with more than one overlap
int overlapCounter(std::vector<std::vector<int>>& overlaps, int dimension){
    int overlapCounter{0};
    for(int i{0}; i<dimension; i++){
        for(int j{0}; j<dimension; j++){
            if(overlaps[i][j]>1){
                overlapCounter += 1;
            }
        }
    }
    return overlapCounter;
}

//prints the overlaps board - diagnostic tool
void boardPrinter(std::vector<std::vector<int>> overlaps,int dimension){
    for(int i{0}; i<dimension; i++){
        for(int j{0}; j<dimension; j++){
            std::cout << overlaps[i][j];
        }
        std::cout << std::endl;
    }
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
        dimension = std::stoi(argv[cmdOptionIndex(argc,argv,"-d")+1]);
    }
    else{
        std::cout << "Error. No grid dimension given." << std::endl;
        return 1;
    }

    //accessing input file
    std::ifstream inputFile(inputFilename);
    if(inputFile){
        std::cout << "File opened successfully\n";
    } 
    else{std::cout << "error opening file\n";}

    //intialising overlap vector
    std::vector<std::vector<int>> overLaps(dimension,
                                           std::vector<int>(dimension));

    //calculating the overlaps
    std::string currentLine;
    int x1, y1, x2, y2;
    std::string orientation;
    while(getline(inputFile,currentLine)){
        std::vector<int> coordinates = lineConverter(currentLine);
        x1 = coordinates[0];
        y1 = coordinates[1];
        x2 = coordinates[2];
        y2 = coordinates[3];
        orientation = lineChecker(x1,y1,x2,y2);
        if(orientation == "nope"){
            continue;
        }
        overlapsUpdater(orientation, x1,y1,x2,y2, overLaps);
    }

    //counting the number of overlaps > 1 and outputting the result
    std::cout << "Number of overlaps: " << overlapCounter(overLaps,dimension) << std::endl;
    
    return 0;

}