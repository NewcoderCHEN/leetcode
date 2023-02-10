#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 滑动窗口
// 超时了
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int elem_num = words.size();
        int elem_size = words[0].size();
        vector<int> result;

        // 按照step分成三类
        for (auto start = 0; start < elem_size; ++start) {
            int left = start;
            while (left + elem_num * elem_size - 1 < s.size()) {
                // 找到第一组符合条件
                while (left + elem_num * elem_size - 1 < s.size()) {
                    if (FindFirstSubStr(s, words, left)) {
                        result.push_back(left);
                        break;
                    }
                    left += elem_size;
                }
                // 滑动窗口
                int right = left + elem_size * (elem_num - 1);
                while (right + elem_size - 1 < s.size()) {
                    right += elem_size;
                    if (find(words.begin(), words.end(), s.substr(right, elem_size)) != words.end()) {
                        // [left] == [right]
                        if (s.substr(left, elem_size) == s.substr(right, elem_size)) {
                            left += elem_size;
                            result.push_back(left);
                            continue;
                        }
                        // [left] != [right]
                        do {
                            left += elem_size;
                        } while (s.substr(left, elem_size) != s.substr(right, elem_size));
                        left += elem_size;
                        if (FindFirstSubStr(s, words, left)) {
                            result.push_back(left);
                            right = left + elem_size * (elem_num - 1);
                            continue;
                        } else {
                            break;
                        }
                    } else {
                        left = right + elem_size;
                        break;
                    }
                }
            }
        }
        return result;
    }

    bool FindFirstSubStr(string s, vector<string>& words, int start) {
        int elem_num = words.size();
        int elem_size = words[0].size();
        // Check if out of range
        if (start + elem_size * elem_num - 1 >= s.size()) {
            return false;
        }

        vector<int> flag(elem_num, 0);
        for (auto i = 0; i < elem_num; ++i) {
            int sub_start = start + i * elem_size;
            vector<int> find_result = FindVector(words, s.substr(sub_start, elem_size));
            if (find_result.empty()) {
                return false;
            }
            int j = 0;
            for ( ; j < find_result.size(); ++j) {
                if (flag[find_result[j]] == 0) {
                    flag[find_result[j]] = 1;
                    break;
                }
            }
            if (j >= find_result.size()) {
                return false;
            }
            // auto iter = find(words.begin(), words.end(), s.substr(sub_start, elem_size));
            // if (iter == words.end() || flag[iter-words.begin()]) { // 没有特定元素或已经search
            //     return false;
            // }
            // flag[iter-words.begin()] = 1;
        }
        return true;
    }

    vector<int> FindVector(vector<string> &words, string str) {
        vector<int> result;
        for (auto i = 0; i < words.size(); ++i) {
            if (words[i] == str) {
                result.push_back(i);
            }
        }
        return result;
    }
};

int main() {
    string s{"wordgoodgoodgoodbestword"};
    vector<string> words{"word","good","best","good"};
    // string str1{"abc"};
    // string str2{"abc"};
    // string str3{"acb"};
    Solution solu;
    // cout << "result: " << solu.FindFirstSubStr(s, words, 0) << endl;
    // cout << "result: " << solu.FindFirstSubStr(s, words, 1) << endl;
    // cout << "result: " << solu.FindFirstSubStr(s, words, 2) << endl;
    // cout << "result: " << solu.FindFirstSubStr(s, words, 3) << endl;
    // cout << "result: " << solu.FindFirstSubStr(s, words, 4) << endl;
    // cout << "str1 == str2: " << (str1 == str2) << endl;
    // cout << "str1 == str2: " << (str1 == str3) << endl;
    cout << "result: " << endl;
    auto result = solu.findSubstring(s, words);
    for (auto i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

}