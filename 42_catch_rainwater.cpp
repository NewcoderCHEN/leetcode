#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 按行求解：会超时
    int trap1(vector<int>& height) {
        int max_height = *max_element(height.begin(), height.end());
        int rainwater = 0;
        for (auto i = 1; i <= max_height; ++i) {
            int start_add = false;
            int temp = 0;
            for (auto j = 0; j < height.size(); ++j) {
                if (!start_add) {
                    if (height[j] >= i) {
                        start_add = true;
                    }
                    continue;
                }
                if (height[j] >= i) {
                    rainwater += temp;
                    temp = 0;
                } else {
                    temp++;
                }
            }
        }
        return rainwater;
    }

    // 按列求解
    int trap2(vector<int>& height) {
        int left, right, tallest;
        int rainwater = 0;
        for (auto i = 1; i < height.size()-1; i++) {
            // The left tallest.
            left = *max_element(height.begin(), height.begin() + i); // 这里要注意，迭代器的重点是需要统计的位置后面一个位置
            // The right tallest.
            right = *max_element(height.begin() + i + 1, height.end());

            tallest = min(left, right);
            if (tallest > height[i]) {
                rainwater += tallest - height[i];
                cout << i << ": " << tallest - height[i] << endl;
            }
        }
        return rainwater;
    }

    // 按列求解:动态规划
    int trap3(vector<int>& height) {
        int left, right, tallest;
        int rainwater = 0;
        if (height.size() > 2) {
            vector<int> max_left(height.size(), 0);
            vector<int> max_right(height.size(), 0);
            for (auto i = 1; i < height.size()-1; i++) {
                max_left[i] = max(max_left[i - 1], height[i - 1]);
            }
            for (auto i = height.size()-2; i > 0; i--) {
                max_right[i] = max(max_right[i + 1], height[i + 1]);
            }
            for (auto i = 1; i < height.size()-1; i++) {
                tallest = min(max_left[i], max_right[i]);
                if (tallest > height[i]) {
                    rainwater += tallest - height[i];
                }
            }
        }
        return rainwater;
    }
};

int main() {
    Solution solu;
    vector<int> input{0};
    int result = solu.trap3(input);
    cout << "result: " << result << endl;
    return 0;
}