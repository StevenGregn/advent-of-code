#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <tuple>
int main() {
    std::fstream input("test.txt");
    if (!input.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    std::string line;
    long long p1 = 0;
    while(std::getline(input, line)) {
        int keep = 12;
        int drop = line.size() - keep;

        for (char c: s) {
            while 
        }
    }

    std::cout << p1 << std::endl;

    return 0;
}