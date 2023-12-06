

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int countBinary(int value){
    int count = 0;
    const uint32_t mask = 0x00000001;
    while(value != 0){
        count += (value & mask);
        value = value >> 1;
    }//end while
    return count;
}

vector<int> countBits(int n) {
    vector<int> result(n + 1);
    for(int i = 0 ; i <= n ;i++){
        result[i] = countBinary(i);
    }//end for i
    return result;
}

int main(){
    // 0   0
    // 1   1
    // 2   1
    // 3   2
    // 4   1
    // 5   2
    // 6   2
    // 7   3
    // 8   1
    // 9   2
    // 10  2
    for(int i = 0 ; i <= 10 ;i++){
        cout << i << " count = " << countBinary(i) << endl; 
    }
    return 0;
}