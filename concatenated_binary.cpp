#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int concatenatedBinary(int n) {
    const int ModValue = 1000000000 + 7;
    long long value = 0;
    int bitLength = 0;

    for(int i = 1; i <= n ;i++){
        // i to binary
        int binValue = i;
        
        if ((i & (i - 1)) == 0) {
            bitLength++;
        }

        value = ((value << bitLength) % ModValue + i) % ModValue;
        // std::cout << std::endl;
    }//end for i
    return value % ModValue;
}

int main(){
    auto result = concatenatedBinary(97947);
    std::cout << "result = " << result << std::endl;
    return 0;
}