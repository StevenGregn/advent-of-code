#include <iostream>
#include <cmath>
#include <fstream>
#include <set>
#include <string>
#include <sstream>

int main(){
    int totalPoints = 0;
    std::ifstream fin; fin.open("input.txt");
    std::set<int> winNums; std::set<int> myNums;
    std::string line;
    if(!fin.is_open()) return 1;
    while(std::getline(fin, line)){
        std::string card = line;
        //std::cout << card << std::endl;
        size_t pipe = card.find('|');
        // get #'s before pipe
        std::string beforePipe = card.substr(0, pipe); //std::cout << beforePipe << std::endl;
        std::istringstream bP(beforePipe); std::string t;
        while(bP >> t){
            try {
                int num = std::stoi(t);
                winNums.insert(num);
            } catch (const std::invalid_argument& e){
                continue;
            }
        }
        // get #'s after the pipe 
        std::string afterPipe = card.substr(pipe + 1); //std::cout << afterPipe << std::endl;
        std::istringstream aP(afterPipe);
        while(aP >> t){
            myNums.insert(std::stoi(t));
        }
        int one = 0; int twoPow = 0;
        for(auto&n:myNums){
            if(winNums.find(n) != winNums.end()){
                if(!one) one = 1; 
                else twoPow += 1;
            }
        }
        int cardTotal = one * static_cast<int>(pow(2, twoPow));
        //std::cout << cardTotal << std:: endl;
        totalPoints += cardTotal;
        winNums.clear(); myNums.clear();
    }
    fin.close();
    // 35639 is too high
    std::cout << "Total Points " << totalPoints << std::endl;
}