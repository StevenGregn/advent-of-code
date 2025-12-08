#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

/*

m -> # of intervals

tc : 
sort -> o(m log m)
merge -> o(m)
for each id(k) binary search -> o(s)

o(mlog(m) + klog(s))

sc: o(m)

*/

int main() {
    std::fstream fin("input.txt");
    if (!fin.is_open()) {
        std::cout << "Error opening file!" << std::endl;
        return 1;
    }
    std::string line = ""; 
    std::vector<std::pair<long long, long long>> interval;
    while(getline(fin, line)){
        if (line.empty()) break;
        int dash = line.find("-");
        long long num_one = stoll(line.substr(0, dash));
        long long num_two = stoll(line.substr(dash + 1)); 
        interval.emplace_back(num_one, num_two);
    }

    std::sort(interval.begin(), interval.end(), [](const auto&a, const auto&b) {
        return a.first < b.first;
    });

    // optimization -> merge intervals where possible
    std::vector<std::pair<long long, long long>> merged;
    for (const auto& iv : interval){
        if (merged.empty() || merged.back().second < iv.first){
            merged.push_back(iv);
        } else {
            merged.back().second = std::max(merged.back().second, iv.second);
        }
    }

    int p1 = 0;
    long long p2 = 0;

    for (const auto& vi: merged){
        p2 += vi.second - vi.first + 1;
    }

    while(getline(fin, line)){
        long long ingredient_id = stoll(line);
        long lo = 0, hi = merged.size() - 1;
        // optimization -> binary search to find the bad ingredient
        while (lo <= hi){
            long mid = (lo + hi) / 2;
            if (ingredient_id < merged[mid].first) hi = mid - 1;
            else if (ingredient_id > merged[mid].second) lo = mid + 1;
            else { 
                p1++;
                break;
            }
        }
        // for (size_t i = 0; i < interval.size(); i++){
        //     if (ingredient_id >= interval[i].first && ingredient_id <= interval[i].second){
        //         ans++;
        //         break;
        //     }
        // }
    }

    std::cout << p1 << std::endl;
    // 231560780 -> too low
    std::cout << p2 << std::endl;
    return 0;
}