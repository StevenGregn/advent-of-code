#include <iostream>
#include <fstream>
#include <string>

std::string find_largest_12_digit(const std::string& line) {
    int n = line.size();
    int start_pos = 0;
    std::string res;
    for (int s = 0; s < 12; s++){
        int search_end = n - (12 - s) + 1;
        char max_digit = '0';
        int max_pos = start_pos;
        for (int j = start_pos; j < search_end; j++){
            if (line[j] > max_digit) {
                max_digit = line[j];
                max_pos = j;
            }

        }

        res += max_digit;
        start_pos = max_pos + 1;
    }

    return res;
}

int main() {
    std::ifstream fin("input.txt");

    if (!fin.is_open()) return 1;
    
    std::string line;
    long long total = 0;

    while(std::getline(fin, line)) { 
        std::string largest = find_largest_12_digit(line);
        total += std::stoll(largest);    
    }
    
    std::cout << "Total joltage: " << total << std::endl;
    
    return 0;
}