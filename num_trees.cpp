/**
 * @file num_trees.cpp
 * @brief 
 * 
 * https://leetcode.cn/problems/unique-binary-search-trees/description
 * 
 * f(1) = 1
 * f(2) = 2
 * f(3) = 5
 * f(4) = ?
 * 
 * 
can(0) = 1
can(1) = 1
can(2) = 2
can(3) = 5
can(4) = 14
can(5) = 42
can(6) = 132
can(7) = 429
can(8) = 1430
can(9) = 4862
can(10) = 16796
can(11) = 58786
can(12) = 208012
can(13) = 742900
can(14) = 2674440
can(15) = 9694845
can(16) = 35357670
can(17) = 129644790
can(18) = 477638700
can(19) = 1767263190
 * 
 * 
 * @version 0.1
 * @date 2024-01-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>

using namespace std;

int catalan(long long n){
    if(n == 0 || n == 1){
        return 1;
    }

    return (catalan(n - 1) * (4 * n  - 2)) / (n + 1);
}

int numTrees(int n) {
    return catalan(n - 1);
}


int main(){
    for(int i = 0 ; i < 30 ; i++){
        cout << "can(" << i << ") = " << catalan(i) << endl;
    }//end for i
    return 0;
}



