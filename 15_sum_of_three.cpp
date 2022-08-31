#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result = {};
        vector<int> result_temp = {};
        int len = nums.size();
        int L;
        int R;
        if ( len <=2 ) { return result; }
        else {
            //Sort(nums);
            sort(nums.begin(), nums.end());  //algorithm里面有现成的排序算法
            for (int vec_num : nums) { cout << vec_num << "  "; }
            cout << endl;
            for (int i=0; i<=len-3; i++) {
                if( i>0 && nums[i]==nums[i-1]) { continue; }
                L = i+1;
                R = len-1;
                while (L<R) {
                    if (nums[i] + nums[L] + nums[R] == 0) {
                        result_temp = {nums[i], nums[L], nums[R]};
                        result.push_back(result_temp);
                        do {
                            L++;
                        } while (nums[L] == nums[L-1] && L < R);
                        do {
                            R--;
                        } while (nums[R] == nums[R+1] && R > L);
                    }
                    else if (nums[i] + nums[L] + nums[R] < 0) {
                        do {
                            L++;
                        } while (nums[L] == nums[L-1] && L < R);
                    }
                    else {
                        do {
                            R--;
                        } while (nums[R] == nums[R+1] && R > L );
                    }
                }
            }
        }

        cout << "result size: " << result.size() << endl;
        for(auto vec_ : result) { Printvec(vec_); }
        return result;
    }
    
    void Sort(vector<int>& nums){
        int len = nums.size();
        int temp;
        for (int i=0; i<len-1; i++){
            for (int j=0; j<(len-i-1); j++) {
                if (nums[j] > nums[j+1]) {
                    temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
            }
        }
    }

    void Printvec(vector<int>& nums){
        for(auto vec : nums){
            cout << vec << "  ";
        }
        cout << endl;
    }
};

int main(){
    Solution solu;
    cout << "start" << endl;
    vector<int> input = {-2,0,0,2,2};
    solu.threeSum(input);
    return 0;
}