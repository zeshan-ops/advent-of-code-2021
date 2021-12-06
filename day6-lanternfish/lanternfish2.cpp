#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main(){
    //READ THE INPUT FILE
    std::string fileName;
    std::cout << "Enter input file name: ";
    std::cin >> fileName;
    std::ifstream inputFile(fileName);

    //mapping the input data into variables that count the number of fishes
    //for each internal timer
    std::vector<long> fishTimers{0,0,0,0,0,0,0,0,0};
    std::string inputData;
    getline(inputFile,inputData);
    std::stringstream ss(inputData);
    
    std::string singleFishTimer;
    std::vector<int> timeValues{0,1,2,3,4,5,6,7,8};
    while(getline(ss,singleFishTimer,',')){
        for(int i{0}; i<9; i++){
            if(std::stoi(singleFishTimer)==timeValues[i]){
                fishTimers[i] += 1;
            }
        }
    }

    //updating the timers over each timestep
    int timeSteps{0};
    std::cout << "\nHow many timesteps: ";
    std::cin >> timeSteps;

    for(int i{0}; i<timeSteps; i++){
        long zeroTimer{0};
        zeroTimer = fishTimers[0];
        for(int j{0}; j<8; j++){
            fishTimers[j] = fishTimers[j+1];
        }
        fishTimers[8] = zeroTimer;
        fishTimers[6] += zeroTimer;
    }

    //counting total number of fish
    long numberOfFish{0};
    for(int i{0}; i<9; i++){
        numberOfFish += fishTimers[i];
    }
    std::cout << "Number of Fish: " << numberOfFish << std::endl;
    
    return 0;
}