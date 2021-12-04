#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>

/*
Program principle:
- boards input into a 3d vector
- scoring tracked in a 3d vector of 0s and 1s
- first line of input into >> scoringNumbers
- each subsequent board into boards
- loop over scoringNumbers{
    scoreUpdater then winChecker;
    break when winner found;
}
*/

//checks the boards for scoring numbers and updates the score vector
void scoreUpdater(std::vector<std::vector<std::vector <int>>> boards,
                  std::vector<std::vector<std::vector <int>>>& score,
                  int drawnNumber){
    for(int i{0}; i<boards.size(); i++){ //loop over each board
        for(int j{0}; j<5; j++){ //loop over each row in a board
            for(int k{0}; k<5; k++){ //loop over each column in a board
                //if drawnNumber found on board, update score
                if(boards[i][j][k]==drawnNumber){
                    score[i][j][k] = 1;
                }
            }
        }
    }
}

//checks if any boards are winning, returns board index 
//if winning board found
void winChecker(std::vector<std::vector<std::vector<int>>>& score, std::vector<int>& winningBoards){
    /*
    in this fn, i is the board number, j is the row,
    k is the column.
    */
    int winning_board{0};
    int Sum{0};
    bool win = false;
    //checking the row sums
    for(int i{0}; i<score.size(); i++){
        if(find(winningBoards.begin(),winningBoards.end(),i) != winningBoards.end()){
            continue;
        }
        for(int j{0}; j<5; j++){
            for(int k{0}; k<5; k++){
                Sum += (int)score[i][j][k];
            }
            if(Sum == 5){
                win = true;
                winningBoards.push_back(i);
                Sum = 0;
                break;
            }
            Sum = 0;
        }
    }
    //checking the column sums
    for(int i{0}; i<score.size(); i++){
        if(find(winningBoards.begin(),winningBoards.end(),i) != winningBoards.end()){
            continue;
        }
        for(int k{0}; k<5; k++){
            for(int j{0}; j<5; j++){
                Sum += (int)score[i][j][k];
            }
            if(Sum == 5){
                win = true;
                winningBoards.push_back(i);
                Sum=0;
                break;
            }
            Sum = 0;
        }   
    }
}

//prints the boards - diagnostic tool
void boardPrinter(std::vector<std::vector<std::vector<int>>> boards){
    for(int i{0}; i<boards.size(); i++){
        std::cout << std::endl << "Board Number: " << i+1 << std::endl;
        for(int j{0}; j<5; j++){
            for(int k{0}; k<5; k++){
                std::cout << boards[i][j][k] << " ";
            }
            std::cout << std::endl;
        }
    }
}

int main(){
    //basic reading the input file stuff
    std::ifstream inputFile ("InputSquidGame2.txt");
    std::string input;
    //taking the first line of the file
    getline(inputFile, input);
    std::vector<int> scoringNumbers; //where our scoringNumbers are stored
    std::stringstream ss(input);

    //puts the scoringNumbers into vector scoringNumbers
    while(ss.good()){
        std::string tmp;
        getline(ss,tmp,',');
        scoringNumbers.push_back(stoi(tmp));
    }

    //where the bingo boards are stored
    std::vector<std::vector<std::vector<int>>> boards(100,std::vector<std::vector<int>>(5,
                                       std::vector<int>(5)));
    //where the score of the boards is stored
    std::vector<std::vector<std::vector<int>>> score(100,std::vector<std::vector<int>>(5,
                                       std::vector<int>(5)));
    
    //filling the boards vector
    for(int i{0}; i<boards.size(); i++){
        for(int j{0}; j<5;j++){
            getline(inputFile,input);
            std::vector<int> singleRow;
            std::stringstream ss_tmp(input);
            while(ss_tmp.good()){
                std::string tmp;
                getline(ss_tmp,tmp, ',');
                singleRow.push_back(stoi(tmp));
            }
            for(int k{0};k<5;k++){
                boards[i][j][k] = singleRow[k];
            }
        }
    }

    //scoring each board and checking for a win at each increment
   int winningNumber{0};
   int winningBoard{0};

   //chronological vector of winning boards
   std::vector<int> winningBoards;

    //loops through scoring numbers, checks for wins, then updates
    //the scorecards
    for(int i{0}; i<scoringNumbers.size();i++){
        winChecker(score, winningBoards);
        if(winningBoards.size()==100){
            winningNumber = scoringNumbers[i-1];
            break;
        }
        scoreUpdater(boards,score,scoringNumbers[i]);
    }

    winningBoard = winningBoards.back();

    //calculating the score of the winning board:
    int unmarkedSum{0};
    for(int j{0}; j<5; j++){
        for(int k{0}; k<5; k++){
            if(score[winningBoard][j][k]==0){
                unmarkedSum += boards[winningBoard][j][k];
            }
        }
    }

    //output - unmarkedSum*winningNumber

    std::cout << "Total Score: " << unmarkedSum*winningNumber << std::endl;

    std::cout << "losing number: " << winningNumber << std::endl;
    std::cout << "losing board: " << winningBoard << std::endl;

    return 0;
}