#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution{
    public:
        string convert(string s, int numRows) {
            if (numRows == 1){
                return s;
            } else{
                int current = 0;
                int godown = true;
                vector< string > row(min(numRows, int(s.size())));  //这里s.size()要格式转化一下

                for (auto c : s){
                    row[current] += c;
                    if ( current == numRows-1 || (current == 0 && !godown) ){
                        godown = !godown;
                    }
                    current += (godown? 1 : -1);
                }

                string ret;
                for (string temp : row){
                    ret += temp;
                }
                return ret;
            }
            
        }
};

int main(){
    string str;
    int num;
    Solution solu;

    cout << "Input the string: " << endl;
    cin >> str;
    cout << "Input the numRows: " << endl;
    cin >> num;
    cout << "The converting result is: " << endl;
    cout << solu.convert(str, num) << endl;

    return 0;
}