/**
 * @author your name 
 * (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-30
 * 
 * https://leetcode.cn/problems/partition-equal-subset-sum/description/?envType=featured-list&envId=2cktkvj?envType=featured-list&envId=2cktkvj
 * 
 * @copyright Copyright (c) 2024
 * 416. 分割等和子集
中等
相关标签
相关企业
给你一个 只包含正整数 的 非空 数组 nums 。
请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPartition(vector<int>& nums) {
    if(nums.empty()){
        return true;
    }

    int total = 0; 
    for(auto &v : nums){
        total += v;
    }

    if(total % 2 != 0){
        return false;
    }

    int halfValue = total / 2;
    sort(nums.begin() , nums.end());

    int preElementTotal = 0;
    int lastElementTotal = 0;
    int left = 0 ; 
    int right = nums.size() - 1;
    bool sumPre = true;
    while(left < right){
        if(sumPre){
            if(preElementTotal + nums[left] <= halfValue){
                preElementTotal += nums[left];
                left++;
            }else{
                sumPre = false;
                continue;
            }

            if(preElementTotal + nums[right] <= halfValue){
                 preElementTotal += nums[right];
                right--;
            }else{
                sumPre = false;
                continue;
            }
        }else{
            lastElementTotal += nums[left++];
            lastElementTotal += nums[right--];
        }
    }//end while

    cout << preElementTotal << " , " << lastElementTotal << endl;
    return preElementTotal == lastElementTotal;
}

int main(){
    vector<int> nums = {1,5,11,5};
    cout << canPartition(nums) << endl;
    return 0;
}