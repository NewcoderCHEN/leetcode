#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
    public:
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
    vector<int> heights{2,1,5,6,2,3};
    Solution solu;
    cout << "the largest rectangle area determined by vector heights is " << endl << solu.largestRectangleArea(heights) << endl;
    return 0;
}