#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <string_view>
void day1A(){
    std::ifstream inputFile; inputFile.open("input.txt");
    int sum = 0;
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
    std::unordered_map<std::string, std::string> dict;
    dict["one"] = "1"; dict["two"] = "2"; dict["three"] = "3"; dict["four"] = "4"; dict["five"] = "5"; dict["six"] = "6"; dict["seven"] = "7"; dict["eight"] = "8"; dict["nine"] = "9";
    std::string names[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int firstOccurence[9] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX};
    std::ifstream inputFile; inputFile.open("input.txt");
    int sum = 0;
    std::string lineInput;
    if(inputFile.is_open()){
        while(true){
            std::string tempString = ""; inputFile >> lineInput;
            std::cout << "Old Input " << lineInput;
            // find first occurrence of each integer
            int minIndex = INT_MAX; std::string minVal = "";
            while(true){
                minIndex = INT_MAX; minVal = ""; bool done = true;
                // get index of first occurrence
                for(int i = 0; i < 9; i++){
                    size_t first = lineInput.find(names[i]);
                    if(first != std::string::npos){
                        firstOccurence[i] = first; done = false;
                    } 
                    //std::cout << i << " " << firstOccurence[i] << " " << std::endl;
                }
                if(done) break;
                // find the first of all the numbers 
                for(int i = 0; i < 9; i++){
                    if(firstOccurence[i] < minIndex){
                        minVal = names[i]; minIndex = firstOccurence[i];
                    } 
                }
                // convert the first string number to equivalent
                if(!minVal.empty() && minIndex != std::string::npos) lineInput.replace(minIndex, dict[minVal].length(), dict[minVal]); //lineInput = lineInput.substr(0, minIndex + dict[minVal].length()) + lineInput.substr(minIndex + dict[minVal].length());
                for(int i = 0; i < 9; i++)firstOccurence[i] = INT_MAX;
                //std::cout << "New Input " << lineInput << std::endl;

            }

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
            std::cout << " New Input " << lineInput << " " << "Grabbed #'s " << tempString << " " << "Trunacted # " << truncated << "\n"; 
            sum += std::stoi(truncated);
            if(inputFile.eof()) break;
        }
    } 
    inputFile.close();
    std::cout << sum << "\n";
}


void processLine(std::string& lineInput, std::unordered_map<std::string, std::string>& dict, const std::string names[]) {
    int firstOccurence[9] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX};
    
    // find first occurrence of each integer
    int minIndex = INT_MAX; std::string minVal = "";
    while (true) {
        minIndex = INT_MAX; minVal = ""; bool done = true;

        // get index of first occurrence
        for (int i = 0; i < 9; i++) {
            size_t first = lineInput.find(names[i]);
            if (first != std::string::npos) {
                firstOccurence[i] = first; done = false;
            }
        }
        if (done) break;

        // find the first of all the numbers
        for (int i = 0; i < 9; i++) {
            if (firstOccurence[i] < minIndex) {
                minVal = names[i]; minIndex = firstOccurence[i];
            }
        }
        // convert the first string number to equivalent
        if (!minVal.empty() && minIndex != std::string::npos) lineInput.replace(minIndex, dict[minVal].length(), dict[minVal]);
        for (int i = 0; i < 9; i++) firstOccurence[i] = INT_MAX;
    }
}

void day1BG() {
constexpr std::array<std::string_view, 9> strDigits{ "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    std::ifstream inf{ "input.txt" };
    int sum{ 0 };

    while (inf) {
        std::string strInput;
        inf >> strInput;

        if (strInput.empty())
            break;

        auto iterL{ std::find_if(strInput.begin(), strInput.end(), [](char c){ return std::isdigit(c); }) };
        int digIndexL{ static_cast<int>(std::distance(strInput.begin(), iterL)) };

        const int lastIndex{ static_cast<int>(strInput.length() - 1) };
        auto iterR{ std::find_if(strInput.rbegin(), strInput.rend(), [](char c){ return std::isdigit(c); }) };
        int digIndexR{ static_cast<int>(lastIndex - std::distance(strInput.rbegin(), iterR)) };
        
        int minIndexL{ -1 };
        int minL{ -1 };

        int maxIndexR{ -1 };
        int maxR{ -1 };

        for (std::string::size_type i{ 0 }; i < 9; ++i) {
            auto strIndexL{ (strInput.find(strDigits[i])) };

            if (std::string::npos != strIndexL) {
                if (minIndexL == -1) {
                    minIndexL = strIndexL;
                    minL = i + 1;
                }
                else if (minIndexL > static_cast<int>(strIndexL)) {
                    minIndexL = strIndexL;
                    minL = i + 1;
                }
            }

            auto strIndexR{ strInput.rfind(strDigits[i]) };

            if (std::string::npos != strIndexR) {
                if (maxIndexR == -1) {
                    maxIndexR = strIndexR;
                    maxR = i + 1;
                }
                else if (maxIndexR < static_cast<int>(strIndexR)) {
                    maxIndexR = strIndexR;
                    maxR = i + 1;
                }
            }
        }

        int l{ -1 };
        if (minIndexL == -1) {
            l = *iterL - '0';
        }
        else{
            if (minIndexL < digIndexL) {
                l = minL;
            }
            else {
                l = *iterL - '0';
            }
        }

        int r{ -1 };
        if (maxIndexR == -1) {
            r = *iterR - '0';
        }
        else {
            if (maxIndexR > digIndexR) {
                r = maxR;
            }
            else {
                r = *iterR - '0';
            }
        }

        sum += (l * 10) + r;
    }
    std::cout << sum << '\n';
}

int main(){
    // day1A();
    // day1B();
    day1BG();
}