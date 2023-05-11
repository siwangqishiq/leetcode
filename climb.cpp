/**
 * @file climb.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-17
 * 
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

int climb(int n , vector<int> &dp){
    if(dp[n]>= 0){
        return dp[n];
    }
    
    int ret = 0;
    if(n == 1){
        ret = 1;
    }else if(n == 2){
        ret = 2;
    }else{
        ret = climb(n - 1 , dp) + climb(n - 2 , dp);
    }
    dp[n] = ret;
    return ret;
}

int climbStairs(int n) {
    vector<int> dpVec(64 , -1);
    return climb(n , dpVec);
}

int main(){
    for(int i = 1 ; i <= 45 ;i++){
        cout << "climbStairs(" << i << ") = " << climbStairs(i) << endl;
    }//end for i
    return 0;
}
