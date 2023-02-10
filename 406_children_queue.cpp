#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    static bool comp (vector<int> &a, vector<int> &b) {
        if (a[0] != b[0]) {
            return a > b;
        }
        return a[1] < b[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 排序：m降序；k升序
        vector<vector<int>> result();
        sort(people.begin(), people.end(), comp);
        // print(people);
        // 插入
        for (auto i = 0; i < people.size(); ++i) {
            auto iter = result.begin();
            result.insert(iter+people[i][1], people[i]);
        }
        // print(result);
        return result;
    }

    // void print(vector<vector<int>> vec) {
    //     std::cout << "print result: " << std::endl;
    //     for (auto i = 0; i < vec.size(); ++i) {
    //         std::cout << vec[i][0] << "  " << vec[i][1] << std::endl;
    //     }
    // }
};

int main() {
    vector<vector<int>> input{{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    Solution solu;
    solu.reconstructQueue(input);
    return 0;
}