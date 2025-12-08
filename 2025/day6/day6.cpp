#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

bool is_number(const std::string& s){
    return !s.empty() && std::all_of(s.begin(), s.end(), [](unsigned char c){
        return std::isdigit(c);
    });
}

int main() {
    std::fstream fin("input.txt");

    if(!fin.is_open()){
        std::cout << "Unable to open file!" << std::endl;
        return 1; 
    }

    std::vector<std::vector<int>> vals;
    std::vector<std::vector<std::string>> vals;

    std::string line_val = "";
    while (std::getline(fin, line_val)) {
        for ()
    }
    
}