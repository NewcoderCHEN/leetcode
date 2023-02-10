#include <iostream>
#include <vector>
using namespace std;

// 滑动窗口
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int num_size = nums.size();
        if (SubArraySum(nums, 0, num_size-1) < target) {
            return 0;
        }

        int result = num_size;
        int left = 0;
        int right = 0;
        int sub_sum = SubArraySum(nums, left, right);
        while (!((right == num_size - 1) && sub_sum < target)) {
            if (sub_sum < target) {
                right++;
                sub_sum += nums[right];
            } else {
                result = min(result, right - left + 1);
                left++;
                sub_sum -= nums[left-1];
            }
        }
        return result;
    }

    int SubArraySum(vector<int>& nums, int L, int R) {
        int sum = 0;
        for (auto i = L; i <= R; ++i) {
            sum += nums[i];
        }
        return sum;
    }
};

int main() {
    vector<int> input{1,1,1,1,1,1,1,1};
    int target{11};
    Solution solu;
    cout << "result: " << solu.minSubArrayLen(target, input) << endl;
}