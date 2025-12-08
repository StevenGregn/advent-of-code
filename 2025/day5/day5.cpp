#include <iostream>
#include <fstream>
#include <vector>
int main() {
    std::ifstream fin("input.txt");

    if (!fin.is_open()) {
        std::cout << "Error opening file!" << std::endl;
        return 1;
    }

    std::vector<std::vector<char>> grid;
    std::vector<std::vector<char>> grid_copy;
    std::string line;
    while (fin >> line) {
        std::vector<char> line_data;
        for (size_t pos = 0; pos < line.size(); pos++){
            line_data.push_back(line[pos]);
        }
        grid.push_back(line_data);
    }

    grid_copy = grid;


    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    std::vector<std::pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {-1,1}, {1,-1}, {-1,-1}};
    int prev_ans = ans;
    do{
        prev_ans = ans;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '@'){
                    int adj_count = 0;
                    for (std::pair p:directions){

                        int dr = p.first + i;
                        int dc = p.second + j;

                        if (dr >= 0 && dr < m && dc >= 0 && dc < n && grid[dr][dc] == '@') {
                            adj_count++;
                        }
                        
                    }
                    if (adj_count < 4) {
                        ans++;
                        grid_copy[i][j] = '.';
                    }
                }
            }
        }
        grid = grid_copy;
    }while (prev_ans < ans);
    
    std::cout << ans << std::endl;
    return 0;
}