#include <iostream>
#include <vector>
using namespace std;

// 并查集
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int num = edges.size();

        // Init.
        Init(num);

        // Traverse and merge.
        for (auto i = 0; i < num; ++i) {
            if (FindFather(edges[i][0]-1) != FindFather(edges[i][1]-1)) { // -1是因为题干中编号是从1开始的
                Merge(edges[i][0] - 1, edges[i][1] - 1);
            } else {
                redundant_con_.push_back(edges[i]);
            }
        }

        // Return.
        return redundant_con_.back();
    }

    void Init(int row) {
        father_.resize(row);
        rank_.resize(row);
        for (auto i = 0; i < row; ++i) {
            father_[i] = i;
            rank_[i] = 1;
        }
    }
    int FindFather(int i) {
        // 路径压缩
        return (i == father_[i]) ? i : father_[i] = FindFather(father_[i]);
    }

    void Merge(int i, int j) {
        // 按秩合并
        int root_i = FindFather(i);
        int root_j = FindFather(j);
        if (rank_[root_i] < rank_[root_j]) {
            father_[root_i] = root_j;
        } else if (rank_[root_i] > rank_[root_j]) {
            father_[root_j] = root_i;
        } else if (root_i != root_j) {
            father_[root_i] = root_j;
            rank_[root_j]++;
        }
    }
private:
    vector<int> father_;
    vector<int> rank_;
    vector<vector<int>> redundant_con_;
};

int main() {
    vector<vector<int>> input{{1,2},{1,3},{2,3}};
    Solution solu;
    vector<int> result = solu.findRedundantConnection(input);
    cout << "result: [" << result[0] << "," << result[1] << "]" << endl;
    return 0;
}