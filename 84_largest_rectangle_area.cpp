#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            int maxArea = 0;
            int left, right;
            int len = heights.size();
            for (int i=0; i < len; i++) {
                for (left = i-1; left >= 0; left--) {
                    if (heights[left] < heights[i]) { break; }
                }
                left++;
                for (right = i+1; right < len; right++) {
                    if (heights[right] < heights[i]) { break; }
                }
                right--;
                maxArea = max(maxArea, heights[i]*(right-left+1));
            }
            return maxArea;
        }
};

int main() {
    vector<int> heights(100000,1);
    Solution solu;
    cout << "the largest rectangle area determined by vector heights is " << endl << solu.largestRectangleArea(heights) << endl;

    return 0;
}