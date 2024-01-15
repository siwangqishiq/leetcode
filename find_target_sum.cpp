/**
 * @file find_target_sum.cpp
 * https://leetcode.cn/problems/target-sum/
 * ?envType=featured-list&envId=2cktkvj?envType=featured-list&envId=2cktkvj
 * 
 * 
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include <iostream>
#include <vector>

using namespace std;

int findTarget(vector<int> &nums , int target , int depth , int preResult){
    if(depth == nums.size()){
        return preResult == target?1:0;
    }else{
        const int curValue = nums[depth];
        const int firstPreResult = preResult + curValue;
        int sumFirst = findTarget(nums , target , depth + 1 , firstPreResult);

        const int secondPreResult = preResult - curValue;
        int sumSecond = findTarget(nums , target , depth + 1 , secondPreResult);
        return sumFirst + sumSecond;
    }
}

int findTargetSumWays(vector<int> &nums, int target) {
    return findTarget(nums , target , 0 , 0);
}

int main(){
    // vector<int> nums = {1,1,1,1,1};
    vector<int> nums = {1};
    cout << "result: " << findTargetSumWays(nums , 1) << endl;
    return 0;
}


