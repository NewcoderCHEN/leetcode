#include <iostream>
#include <vector>
using namespace std;

// DFS 
// 虽然是用DFS方法来实现的遍历，但是解法并不巧妙
class Solution1 {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // Init
        row = grid.size();
        column = grid[0].size();
        vector<int> temp(4,0); // up 0, down 1, left 2, right 3
        vector<vector<int>> temp1(column,temp);
        vector<vector<vector<int>>> temp2(row, temp1);

        for (auto i = 0; i < row; ++i) {
            for (auto j = 0; j < column; ++j) {
                if (grid[i][j] == 1) { // 只有一个岛屿，找到一个起点即可
                    dfs(temp2, grid, i, j, 2);
                }
            }
        }

        return perimeter;
    }

    void dfs(vector<vector<vector<int>>>& temp, vector<vector<int>>& grid, int i, int j, int dir) {
        // 1 Base Case
        // 1.1 Out of range
        if ((i == -1) || (i == row) || (j == -1) || (j == column)) {
            return;
        }
        // 1.2 The block is sea
        if (grid[i][j] == 0) {
            return;
        }
        // 1.3 The block has been searched
        if (grid[i][j] == 2) {
            // 这里是针对边，如果某一条边已经被减过了，就做标记，并且不再继续-2
            if (temp[i][j][dir] == 0) {
                perimeter -= 2;
                temp[i][j][dir] = 1;
                if (dir == 0) {
                    temp[i-1][j][1] = 1;
                } else if (dir == 1) {
                    temp[i+1][j][0] = 1;
                } else if (dir == 2) {
                    temp[i][j-1][3] = 1;
                } else {
                    temp[i][j+1][2] = 1;
                }
            }
            return;
        }

        // 2 Set condition
        grid[i][j] = 2;
        perimeter += 4;

        // 3 DFS recursively
        dfs(temp, grid, i-1, j, 1); // up
        dfs(temp, grid, i+1, j, 0); // down
        dfs(temp, grid, i, j-1, 3); // left
        dfs(temp, grid, i, j+1, 2); // right
    }
private:
    int row;
    int column;
    int perimeter{0};
};

// DFS 
// 巧妙的解法
class Solution2 {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // Init
        row = grid.size();
        column = grid[0].size();

        for (auto i = 0; i < row; ++i) {
            for (auto j = 0; j < column; ++j) {
                if (grid[i][j] == 1) { // 只有一个岛屿，找到一个起点即可
                    dfs(grid, i, j);
                }
            }
        }

        return perimeter;
    }

    void dfs(vector<vector<int>>& grid, int i, int j) {
        // dfs框架是一样的，三步走：终止条件（越界、海洋、已经search）、设置flag、递归dfs
        // 关键是如何把问题求解的数学关系，融合到这个过程里面
        // 这道题巧妙在，所求解的周长，恰好是岛屿和海洋分解、和越界分解的和
        // 所以可以直接在终止条件中，对周长进行累积

        // 1 Base Case
        // 1.1 Out of range
        if ((i == -1) || (i == row) || (j == -1) || (j == column)) {
            perimeter++;
            return;
        }
        // 1.2 The block is sea
        if (grid[i][j] == 0) {
            perimeter++;
            return;
        }
        // 1.3 The block has been searched
        if (grid[i][j] == 2) {
            return;
        }

        // 2 Set condition
        grid[i][j] = 2;

        // 3 DFS recursively
        dfs(grid, i-1, j); // up
        dfs(grid, i+1, j); // down
        dfs(grid, i, j-1); // left
        dfs(grid, i, j+1); // right
    }
private:
    int row;
    int column;
    int perimeter{0};
};

int main() {
    vector<vector<int>> input{{1, 1},{1, 1}};
    Solution2 solu;
    cout << "Result: " << solu.islandPerimeter(input) << endl;
}