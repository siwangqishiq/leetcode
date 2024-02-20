/**
 * @file length_lis.cpp
 * @brief 
 * @version 0.1
 * @date 2024-02-05
 *  https://leetcode.cn/problems/longest-increasing-subsequence
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

int lis(vector<int> &nums , int start){
    int curValue = nums[start];
    int length = 1;
    vector<int> sub;
    sub.push_back(curValue);
    int index = start + 1;
    
    while(index < nums.size()){
        if(curValue < nums[index]){
            cout << "curValue = " << curValue << "  " << nums[index] <<endl;
            curValue = nums[index];
            sub.push_back(nums[index]);
            length++;
        }
        index++;
    }//end while

    for(auto &v : sub){
        cout << v << "  ";
    }
    cout << endl;
    return length;
}

int lengthOfLIS(vector<int>& nums) {
    int longest = 0;
    for(int i = 0 ; i < nums.size() ; i++){
        int len = lis(nums , i);
        // cout << " i = " << i << " longest = " << len << endl;
        if(len > longest){
            longest = len;
        }
    }//end for i
    return longest;
}


int main(){
    vector<int> nums = {0,1,0,3,2,3};
    cout << lengthOfLIS(nums) << endl;
    return 0;
}
