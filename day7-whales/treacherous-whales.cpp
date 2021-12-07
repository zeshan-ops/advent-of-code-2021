#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

//main program
int main(){
    //reading the input file
    std::string fileName;
    std::cout << "Enter input filename: ";
    std::cin >> fileName;
    std::ifstream inputFile(fileName);

    //mapping the input file to a vector
    std::string inputData;
    getline(inputFile,inputData);
    std::stringstream ss(inputData);

    std::vector<int> crabPositions;

    std::string singlePosition;
    while(getline(ss,singlePosition, ',')){
        crabPositions.push_back(stoi(singlePosition));
    }

    //finding the max value in the crabPositions vector
    int max = *std::max_element(crabPositions.begin(),crabPositions.end());

    //finding the smallest fuel consumption
    int lowestFuelConsumption{2147483647};
    int bestPosition{0};
    for(int i{0};i<max;i++){
        int fuelConsumption{0};
        for(int j{0};j<crabPositions.size();j++){
            fuelConsumption += abs(crabPositions[j]-i);
        }
        if(fuelConsumption < lowestFuelConsumption){
            bestPosition = i;
            lowestFuelConsumption = fuelConsumption;
        }
    }

    //finding the smalles fuel consumption for part 2
    int lowestFuelConsumption2{2147483647};
    int bestPosition2{0};
    for(int i{0};i<max;i++){
        int distance{0};
        int fuelConsumption2{0};
        for(int j{0};j<crabPositions.size();j++){
            distance = abs(crabPositions[j]-i);
            for(int k{1};k<distance+1;k++){
                fuelConsumption2 += k;
            }
        }
        if(fuelConsumption2 < lowestFuelConsumption2){
            bestPosition2 = i;
            lowestFuelConsumption2 = fuelConsumption2;
        }
    }
    std::cout << "Best x position (part 1): " << bestPosition << std::endl;
    std::cout << "Lowest fuel consumption (part 1): " << lowestFuelConsumption << std::endl;

    std::cout << "Best x position (part 2): " << bestPosition2 << std::endl;
    std::cout << "Lowest fuel consumption (part 2): " << lowestFuelConsumption2 << std::endl;
    return 0;
}