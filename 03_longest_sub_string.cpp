#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        int max_sub = 1;
        int left = 0;
        int right = 0;
        string sub_str = s.substr(left, right - left + 1);
        while (right < s.size()) {
            if (sub_str.find(s[right]) == (sub_str.size() - 1)) {
                max_sub = max(max_sub, right - left + 1);
                right++;
            } else {
                left++;
            }
            sub_str = s.substr(left, right - left + 1);
        }
        return max_sub;
    }
};

int main() {
    string str{""};
    Solution solu;
    cout << "result: " << solu.lengthOfLongestSubstring(str) << endl;
    // cout << "try: " << str[0] << str[1] << str.find(str[0])<< endl;
    return 0;
}