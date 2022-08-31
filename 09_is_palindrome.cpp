#include <iostream>
#include <cmath>

class Solution{
    public:
        bool isPalindrome(int x){
            if (x<0) return false;

            int remain = x;
            int result = 0;
            do
            {
                if (result > int(pow(2,31)/10) || result == int(pow(2,31)/10) && remain%10>7 ) return false;
                result = result*10 + remain%10;
                remain = remain/10;
            } while (remain!=0);
            
            if (result == x) return true;
            else return false;
            
        }
};

int main(){
    Solution solu;
    int input;
    std::cin >> input;
    std::cout << solu.isPalindrome(input) << std::endl;
    return 0;
}