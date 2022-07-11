#include <iostream>
#include <cmath>
using namespace std;

class Solution{
    public:
        int reverse(int x) {
            if ( x>-10 && x<10 ){
                return x;
            } else {
                int ret = 0;
                int remain;
                bool  Ispositive = x>0 ? 1: 0;
                do
                {
                    remain = x%10; 
                    if ( Ispositive && ((ret<pow(2,31)/10) || (ret==pow(2,31)/10 && remain<=7)) ){
                        ret = ret*10 + remain;
                        x = x/10;
                    } else if ( !Ispositive && ((ret>pow(2,31)/-10) || (ret==pow(2,31)/-10 && remain>=-8)) )
                    {
                        ret = ret*10 + remain;
                        x = x/10;
                    }
                    else return 0;
                } while ( x!=0 );
                
                return ret;
                //return ret*Ispositive < pow(2,31)-1 && ret*Ispositive > -1*pow(2,31) ? ret*Ispositive : 0;
            }
        }
};

int main(){
    Solution solu;
    cout << solu.reverse(-2147483648) << endl;

    return 0;
}