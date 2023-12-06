/**
 * @file find_disappear.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-15
 * 
 * 给你一个含 n 个整数的数组 nums ，
 * 其中 nums[i] 在区间 [1, n] 内。
 * 请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> result;
    if(nums.empty()){
        return result;
    }

    unordered_map<int , int> numsMap;
    const int n = nums.size();

    for(int value : nums){
        numsMap[value] = 1;
    }//end for each

    for(int i = 1 ; i <= n ; i++){
        if(numsMap.find(i) == numsMap.end()){
            result.emplace_back(i);
        }
    }//end for i

    return result;
}

int main(){
    return 0;
}