#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

class Solution{
    public:
        string intToRoman(int num){
            vector<string> roman_ = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
            vector<int> int_ = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
            string result;
            int divisor = 0;
            int i=0;
            while( num!=0) {
                divisor = num / int_[i];
                num = num % int_[i];
                if ( divisor > 0 ) {
                    for(int j=0; j<divisor; j++){
                        result += roman_[i];
                    } }
                i++;
            }

            return result;

        }
};

int main(){
    Solution solu;
    cout << solu.intToRoman(1994) << endl;
}