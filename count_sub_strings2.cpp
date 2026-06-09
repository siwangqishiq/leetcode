#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printDp(vector<vector<bool>> &dp,const int size) {
    for(int i = 0 ; i < size; i++){
        for(int j =0; j < size; j++) {
            cout << dp[i][j] << " ";
        }// end for j
        std::cout << std::endl;
    }//end for i
} 

int countSubstrings(string s){
    const int size = s.length();
    
    int subCounter = 0;
    vector<vector<bool>> dp(size, vector<bool>(size, false));
    for(int i = 0 ; i < size ;i++) {
        dp[i][i] = true;
        subCounter++;
    }//end for i

    // printDp(dp, size);
    
    int len = 1;
    while(len <= size) {
        for(int i = 0; i < size - len; i++){
            int j = i + len;
            // std::cout << i << "," << j << std::endl;
            bool isSame = s[i] == s[j];
            std::cout << i << "," << j << " is_same = " << isSame <<std::endl;
            if(j - i <= 1){
                dp[i][j] = isSame;
            }else {
                dp[i][j] = dp[i + 1][j - 1] && isSame;
            }
            
            if(dp[i][j]){
                subCounter++;
            }
        }//end for i

        len++;
    }//end while

    // printDp(dp, size);
    return subCounter;
}

int main(){
    string s = "aaaaa";
    auto result = countSubstrings(s);
    std::cout << "result = " << result << std::endl;
    return 0;
}
