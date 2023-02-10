#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

// 解法1：并查集
class Solution1 {
  public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int column = grid[0].size();

        // 1 Init the relationship.
        Init(row, column);
        count = 0; // 用于统计岛屿数量

        // 2 Traverse and merge.
        for (auto i = 0; i < row; ++i) {
            for (auto j = 0; j < column; ++j) {
                if (grid[i][j] == '1') {
                    count++; // 每碰到一次陆地，岛屿+1
                    if ((i != 0) && grid[i-1][j] == '1') {
                        Merge(i, j, i-1, j);
                    }
                    if ((j != 0) && grid[i][j-1] == '1') {
                        Merge(i, j, i, j-1);
                    }
                }
            }
        }

        return count;
    }
    
    void Init(int& row, int& column) {
        rank.resize(row);
        father.resize(row);
        for (auto i = 0; i < row; ++i) {
            rank[i].resize(column);
            father[i].resize(column);
            for (auto j = 0; j < column; ++j) {
                rank[i][j] = 1;
                father[i][j] = pair<int, int>(i, j);
            }
        }
        // cout << "try: " << rank.size() << "  " << rank[0].size() << endl;
    }

    // 路径压缩
    pair<int, int> FindFather(int& i, int& j) {
        if (pair<int, int>(i, j) == father[i][j]) {
            return pair<int, int>(i, j);
        }
        father[i][j] = FindFather(father[i][j].first, father[i][j].second);
        return father[i][j];
    }

    // 按秩合并
    void Merge(int e1_i, int e1_j, int e2_i, int e2_j) {
        pair<int, int> e1 = FindFather(e1_i, e1_j);
        pair<int, int> e2 = FindFather(e2_i, e2_j);

        // 深度浅的树合并到深度深的树上
        if (rank[e1.first][e1.second] < rank[e2.first][e2.second]) { // tree1深度比tree2深度浅
            father[e1.first][e1.second] = e2;
            count--;
        } else if (rank[e1.first][e1.second] > rank[e2.first][e2.second]) { // tree2深度比tree1深度浅
            father[e2.first][e2.second] = e1;
            count--;
        } else { // tree1深度与tree2深度一致
            if (e1 != e2) { // tree1和tree不是同一棵树（如果是同一棵树则不做处理）
                father[e1.first][e1.second] = e2;
                count--;
                rank[e2.first][e2.second]++;
            }
        }
    }

  private:
    vector<vector<int>> rank;
    vector<vector<pair<int, int>>> father;
    int count;
};

// 解法2：DFS算法（Depth-First-Search，深度优先搜索算法）
class Solution2 {
  public:
    int numIslands(vector<vector<char>>& grid) {
        // Init
        grid_replace = grid;
        row = grid.size();
        column = grid[0].size();
        count = 0;

        // Traverse
        for (auto i = 0; i < row; ++i) {
            for (auto j = 0; j < column; ++j) {
                count += dfs(i, j);
            }
        }
        return count;
    }
    int dfs(int i, int j) {
        // 1 Base Case
        // 1.1 The block is out of range.
        if ((i == -1) || (i == row) || (j == -1) || (j == column)) {
            return 0;
        }
        // 1.2 The block is sea
        if (grid_replace[i][j] == '0') {
            return 0;
        }
        // 1.3 The block has been  searched
        if (grid_replace[i][j] == '2') {
            return 0;
        }

        // 2 Set flag to determine the block has been searched.
        grid_replace[i][j] = '2';

        // 3 dfs the related blocks.
        dfs(i-1, j); // up
        dfs(i+1, j); // down
        dfs(i, j-1); // left
        dfs(i, j+1); // right
        return 1;
    }
  private:
    int row;
    int column;
    vector<vector<char>> grid_replace;
    int count;
};

int main() {
    vector<vector<char>> input{{'1'},{'0'}};
    Solution2 solu;
    cout << "result: " << solu.numIslands(input) << endl;
    return 0;
}