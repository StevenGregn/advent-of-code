#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <set>

void day1A(){
    std::ifstream inputFile; inputFile.open("input.txt");
    int sum;
    int lineNum;
    std::string lineInput;
    if(inputFile.is_open()){
        while(true){
            std::string tempString = "";
            inputFile >> lineInput;
            for(int i = 0; i < lineInput.length(); i++){
                if(isdigit(lineInput[i])){
                    tempString += lineInput[i];
                }
            }
            
            std::string truncated = "";
            if(tempString.length() == 1){
                truncated += tempString[0];
                truncated += tempString[0];
            }else{
                truncated += tempString[0];
                truncated += tempString[tempString.length() - 1];
            }
            sum += std::stoi(truncated);
            if(inputFile.eof()) break;
        }
    } 
    inputFile.close();
    std::cout << sum << "\n";
}

void day1B(){
    std::set<std::string> nums;
    nums.insert("one");
    nums.insert("two");
    nums.insert("three");
    nums.insert("four");
    nums.insert("five");
    nums.insert("six");
    nums.insert("seven");
    nums.insert("eight");
    nums.insert("nine");
    std::ifstream inputFile; inputFile.open("input.txt");
    int sum;
    int lineNum;
    std::string lineInput;
    if(inputFile.is_open()){
        while(true){
            std::string tempString = "";
            inputFile >> lineInput;
            for(int i = 0; i < lineInput.length(); i++){
                if(isdigit(lineInput[i])){
                    tempString += lineInput[i];
                }
            }
            
            std::string truncated = "";
            if(tempString.length() == 1){
                truncated += tempString[0];
                truncated += tempString[0];
            }else{
                truncated += tempString[0];
                truncated += tempString[tempString.length() - 1];
            }
            sum += std::stoi(truncated);
            if(inputFile.eof()) break;
        }
    } 
    inputFile.close();
    std::cout << sum << "\n";
}

int main(){
    day1A();
}