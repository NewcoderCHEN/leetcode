#include <iostream>
#include <vector>
using namespace std;

// 并查集
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // Init
        int row = isConnected.size(); // row == column
        Init(row);

        // Traverse and merge
        for (auto i = 0; i < row; ++i) {
            for (auto j = i; j < row; ++j) {
                if (isConnected[i][j] == 1) {
                    Merge(i, j);
                }
            }
        }

        return count_;
    }

    void Init(int& row) {
        count_ = row;
        father_.resize(row);
        rank_.resize(row);
        for (auto i = 0; i < row; ++i) {
            father_[i] = i;
            rank_[i] = 1;
        }
    }

    int FindFather(int& i) {
        // 路径压缩
        if (i == father_[i]) {
            return i;
        }
        father_[i] = FindFather(father_[i]);
        return father_[i];
        // return (i == father_[i]) ? i : father_[i] = FindFather(father_[i]);
    }

    void Merge(int &i, int &j) {
        int root_i = FindFather(i);
        int root_j = FindFather(j);
        // 按秩合并
        // 深度浅的tree挂在到深度深的tree上面
        if (rank_[root_i] < rank_[root_j]) {
            father_[root_i] = root_j;
            count_--;
        } else if (rank_[root_i] > rank_[root_j]) {
            father_[root_j] = root_i;
            count_--;
        } else if (root_i != root_j) { // 深度一致时，只处理不同的两棵tree
            father_[root_i] = root_j;
            count_--;
            rank_[root_j]++;
        }
    }
private:
    int count_;
    vector<int> father_;
    vector<int> rank_;
};

int main() {
    vector<vector<int>> input{{1,0,0}, {0,1,0}, {0,0,1}};
    Solution solu;
    cout << "result: " << solu.findCircleNum(input) << endl;
}