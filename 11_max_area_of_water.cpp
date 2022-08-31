#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> height) {
        int start_point = 0;
        int end_point = height.size()-1;
        int area = 0;
        int max_area = 0;

        do
        {
            area = min(height[start_point], height[end_point])*(end_point-start_point);
            max_area = max( area, max_area );
            if (height[start_point]<height[end_point]) start_point++;
            else end_point--;
        } while (start_point != end_point);
        

        return max_area;
    }
};

int main(){
    Solution solu;
    cout << solu.maxArea({1,8,6,2,5,4,8,3,7}) << std::endl;
}