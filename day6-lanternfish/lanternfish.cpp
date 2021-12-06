#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

int main(){
    //READ THE INPUT FILE
    std::string fileName;
    std::cout << "Enter input file name: ";
    std::cin >> fileName;
    std::ifstream inputFile(fileName);

    //EXTRACT INPUT FILE DATA INTO VECTOR
    std::vector<int> daFishes;
    std::string initialTimers;
    getline(inputFile,initialTimers);
    std::stringstream ss(initialTimers);
    std::string singleInitialTimer;
    while(getline(ss,singleInitialTimer,',')){
        daFishes.push_back(std::stoi(singleInitialTimer));
    }

    std::cout << "Initial Vector:" << std::endl;

    for(auto i: daFishes){
        std::cout << i << " ";
    }

    //UPDATE THE FISHES VECTOR FOR EACH TIMESTEP
    int timeSteps{0};
    int NewFishes{0};
    std::cout << "\nEnter # of timesteps to, like, simulate, bro: ";
    std::cin >> timeSteps;
    for(int i{0}; i<timeSteps; i++){
        for(int i{0}; i<daFishes.size()-NewFishes;i++){
            if(daFishes[i]==0){
                daFishes[i]=6;
                daFishes.push_back(8);
                NewFishes += 1;
                continue;
            }
            else{daFishes[i] += -1;}
        }
        NewFishes = 0;
    }
    std::cout << "\nThe number of fishes, bro, is like, probably, " << daFishes.size() << " bro." << std::endl;
    return 0;
}