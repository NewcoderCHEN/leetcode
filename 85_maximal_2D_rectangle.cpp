#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 单调栈
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> heights(matrix[0].size(), 0);
        int max_area = 0;
        for (auto i=0; i < matrix.size(); ++i) {
            for (auto j = 0; j < heights.size(); ++j) {
                heights[j] = 0;
                for (auto elem = i; elem < matrix.size(); ++elem){
                    if (matrix[elem][j] == '0') {
                        break;
                    }
                    heights[j]++;
                }
            }
            max_area = max(max_area, largestRectangleArea(heights));
            heights.pop_back();  // 这里一定要pop_back，因为调用largestRectangleArea里面往heights push了一个0
        }
        return max_area;
    }

    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int max_area = 0;
        int left;
        int right;
        int height;
        std::stack<int> up_node;
        for (int i = 0; i < heights.size(); ++i) {
            while (!up_node.empty() && heights[up_node.top()] >= heights[i]) {
                height= heights[up_node.top()];
                up_node.pop();
                left = up_node.empty() ? -1 : up_node.top();
                right = i;
                max_area = std::max(max_area, height * (right - left - 1));
            }
            up_node.push(i);
        }
        return max_area;
    }
};

int main() {
    vector<vector<char>> input = {{'0'},{'0'}};
    Solution solu;
    cout << "The maximal rectangle area in the 2D binary matrix is: " << solu.maximalRectangle(input) << endl;
    return 0;
}
