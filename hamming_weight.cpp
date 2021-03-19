#include <iostream>

using namespace std;

int hammingWeight(uint32_t n){
    int count = 0;
    char buf[64];

    while(n != 0){
        // itoa(n , buf , 2);
        // cout << buf << endl; 
        uint32_t mask = (n >> 1)<<1;
        if((n ^ mask) == 1){
            count++;
        }
        n = n >> 1;
    }//end while
    
    return count;
}

int main(){
    int hamWeight = hammingWeight(0b11111111111111111111111111111101);
    cout << "hamWeight = " << hamWeight << endl; 
    return 0;
}

