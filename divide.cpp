
#include <iostream>

using namespace std;

int divide(int dividend, int divisor) {
    int result = 0;

    int flag = (dividend >0 && divisor >0) || (dividend <0 && divisor <0)?1:-1;

    if(dividend < 0){
        dividend = -dividend;
    }

    if(divisor < 0){
        divisor = -divisor;
    }

    int count = 0;
    
    
    return (flag > 0)?result:-result;
}

int main(){
    cout << divide(9 , 3) << endl;
    return 0;
}