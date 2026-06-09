#include <iostream>
#include <string>

using namespace std;


void printDp(bool *dp[], int size) {
    for(int i = 0 ; i < size ;i++) {
        for(int j = 0; j < size; j++) {
            cout << dp[i][j] << "  ";
        }
        cout << endl;
    }
}

int countSubstrings(string s){
    if(s.empty()) {
        return 0;
    }

    const int size = s.length();
    bool dp[size][size];

    //init 
    for(int i = 0 ; i < size ; i++){
        for(int j = 0; j< size ; j++){
            dp[i][j] = false;
        }
    }

    for(int i = 0; i < size ; i++){
        dp[i][i] = true;
    }//end for i

    for(int l = 2 ; l <= size; l++){
        for(int i = 0; i < size - l; i++){
            bool isSame = s[i] == s[i + l];
            dp[i][i + l] = dp[i + 1][i + l - 1] && isSame; 
        }//end for i
    }//end for l

    printDp(static_cast<bool **>(dp), size);
    
    return dp[0][size - 1];
}


int main() {
    string s = "aaaa";
    auto subCount = countSubstrings(s);
    
    std::cout << "sub palindrome count = " << subCount << std::endl;
    return 0;
}
