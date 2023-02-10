#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 单调栈
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> down_node;
        for (auto i = 0; i < temperatures.size(); ++i) {
            while(!down_node.empty() && temperatures[down_node.top()] < temperatures[i]) {
                result[down_node.top()] = i - down_node.top();
                down_node.pop();
            }
            down_node.push(i);
        }
        return result;
    }
};

int main() {
    vector<int> temp = {73,74,75,71,69,72,76,73};
    Solution solu;
    auto result = solu.dailyTemperatures(temp);
    cout << "Result: " << endl;
    for (auto i = 0; i < temp.size(); ++i) {
        cout << result[i] << " ";
    }
}