#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution{
    public:
        int myAtoi(string s){
            long result = 0;
            int i;
            int length = s.length();
            int Ispositive = 1;
            vector <char> number = {'0','1','2','3','4','5','6','7','8','9'};
            vector <char> label = {'-', '+'};

            for (i = 0; i < length; i++){
                if(count(number.begin(), number.end(), s[i])){
                    result = s[i]-'0';
                    break;
                }else if (count(label.begin(), label.end(), s[i])){
                    if (i<length-1 && count(number.begin(), number.end(), s[i+1])){
                        result = s[i+1]-'0';
                        if(s[i] == '-') Ispositive = -1;
                        i = i+1;
                        break;
                    } else return 0;
                }else{
                    if (s[i]!=' ') return 0;
                }
            }
            result = result*Ispositive;
            if(i<length-1){
                for (size_t j = i+1; j < length; j++){
                    if (!count(number.begin(), number.end(), s[j])){ 
                        break;
                    }
                    if (result_safe(result, s[j]-'0')){
                        if (Ispositive == 1) result = result*10+s[j]-'0';
                        else result = result*10-(s[j]-'0');
                    }else{
                        if(Ispositive > 0) return pow(2,31)-1;
                        else return -1*pow(2,31);
                    }
                }
            }
            return result;
        }

        bool result_safe(int now, int remain){
            if( now>=0 && (now<int(pow(2,31)/10) || (now==int(pow(2,31)/10) && remain<7) ) ){
                return true;
            }else if ( now<0 && (now>int(pow(2,31)/-10) || (now==int(pow(2,31)/-10) && remain<8))){
                return true;
            }else return false;
        }
};

int main(){
    Solution solu;
    cout << solu.myAtoi("-2147483649") << std::endl;
    return 0;
}