#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution{
    public:
        int romanToInt(string s){
            int len = s.length();
            int result = 0;
            for (int i = len-1; i>=0; i--) {
                if ( (i < len-1) && (umap.at(s[i]) < umap.at(s[i+1])) ){
                    result -= umap.at(s[i]);
                }
                else {
                    result += umap.at(s[i]);
                }
            }

            return result;
        }
    private:
        unordered_map <char, int> umap{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

};

int main(){
    Solution solu;
    cout << solu.romanToInt("III") << endl;
    return 0;
}