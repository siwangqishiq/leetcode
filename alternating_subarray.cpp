/**
 * @file alternating_subarray.cpp
    https://leetcode.cn/problems/longest-alternating-subarray
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int> &array){
    cout << "[ ";
    for(auto &v : array){
        cout << v << " ";
    }//end for each
    cout << "]" << endl;
}

bool isAlternating(vector<int> &array){
    if(array.size() < 2 || array[1] - array[0] != 1){
        return false;
    }

    for(int i = 2 ; i < array.size() ;i++){
        int flag = (i % 2 == 0)? -1:1;
        if(array[i] - array[i - 1] != flag){
            return false;
        }
    }//end for i
    return true;
}

int alternatingSubarray(vector<int>& nums) {
    int len = nums.size();
    while(len > 0){
        int start = 0;
        while(start + len <= nums.size()){
            vector<int> subArray(nums.begin() + start , nums.begin() + start + len);
            // printArray(subArray);
            if(isAlternating(subArray)){
                return len;
            }
            start++;
        }
        len--;
    }//end while
    return -1;
}

int main(){
    vector<int> data = {4,5,6,9};
    cout << alternatingSubarray(data) << endl;
    // cout << isAlternating(data) << endl;
    return 0;
}

