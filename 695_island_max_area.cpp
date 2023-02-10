#include <iostream>
#include <vector>
using namespace std;

// DFS
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // Init
        row = grid.size();
        column = grid[0].size();
        max_area = 0;

        // Traverse and count
        for (auto i = 0; i < row; ++i) {
            for (auto j = 0; j < column; ++j) {
                max_area = max(dfs(grid, i, j), max_area);
            }
        }
        
        // Return
        return max_area;
    }

    // 返回以(i,j)点为起点的相关陆地面积
    int dfs(vector<vector<int>>& grid, int i, int j) {
        // 1 Base case
        // 1.1 the block is out of range.
        if ((i == -1) || (i == row) || (j == -1) || (j == column)) {
            return 0;
        }
        // 1.2 the block is sea.
        if (grid[i][j] == 0) {
            return 0;
        }
        // 1.3 the block has been searched.
        if (grid[i][j] == 2) {
            return 0;
        }

        // 2 Set condition
        grid[i][j] = 2;
        int area = 1;

        // 3 dfs the related blocks.
        area += dfs(grid, i-1, j); // up
        area += dfs(grid, i+1, j); // down
        area += dfs(grid, i, j-1); // left
        area += dfs(grid, i, j+1); // right

        // return
        return area;
    }

private:
    int row;
    int column;
    int max_area;
};

int main() {
    vector<vector<int>> input{{1,0},{1,0}};
    Solution solu;
    cout << "Result: " << solu.maxAreaOfIsland(input) << endl;
}