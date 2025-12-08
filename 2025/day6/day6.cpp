#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <numeric>
#include <sstream>

std::vector<long long> get_nums(const std::string& s){
    std::stringstream ss(s);
    std::vector<long long> res; 
    long long x;

    while (ss >> x) {
        res.emplace_back(x);
    }
    return res;
}

int main() {
    std::fstream fin("input.txt");

    if(!fin.is_open()){
        std::cout << "Unable to open file!" << std::endl;
        return 1; 
    }

    std::vector<long long> nums;
    std::vector<char> sign;
    std::string line_val;
    char sign_val;

    std::getline(fin, line_val);
    std::stringstream ss(line_val);
    while (ss >> sign_val){
        sign.emplace_back(sign_val);
    }

    while (std::getline(fin, line_val)) {
        std::vector<long long> line_nums = get_nums(line_val);
        if (nums.empty()){
            nums = line_nums;
        } else {
            for (size_t i = 0; i < line_nums.size(); i++){
                nums[i] = sign[i] == '+' ? nums[i] + line_nums[i] :  nums[i] * line_nums[i];
            }
        }            
        
    }

    long long p1 = std::accumulate(nums.begin(), nums.end(), 0LL);
    std::cout << p1 << std::endl;
    
}