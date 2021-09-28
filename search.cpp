/**
 * 整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。

 

示例 1：

输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4
示例 2：

输入：nums = [4,5,6,7,0,1,2], target = 3
输出：-1
示例 3：

输入：nums = [1], target = 0
输出：-1

链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array
 * 
 * 
 * 
 * */
#include <iostream>
#include <vector>

using namespace std;

int findRotateIndex(vector<int> &nums){
    int priorValue = nums[0];
    for(int i = 1 ; i < nums.size() ;i++){
        if(priorValue > nums[i]){
            return i - 1;
        }
        priorValue = nums[i];     
    }//end for i
    return 0;
}

int binarySearch(vector<int> &data ,int target, int start , int end){
    if(end >= data.size())
        return -1;

    if(end < start){
        return -1;
    }else if(end == start){
        return data[start] == target? start : -1; 
    }
    
    int left = start;
    int right = end;

    int mid = (left + right) / 2;
    //cout <<"left "<< left << " right "<< right << " mid = " << mid << endl;
    if(data[mid] > target){
        return binarySearch(data , target , start , mid);
    }else if(data[mid] < target){
        if(mid == start){
            return data[right] == target? right : -1; 
        }
        return binarySearch(data , target , mid , end);
    }else{
        return mid;
    }
}

int search(vector<int>& nums, int target) {
    if(nums.empty())
        return -1;

    int rotateIndex = findRotateIndex(nums);
    // cout << "rotate Index pos " << rotateIndex << endl;
    int result = binarySearch(nums , target , 0 , rotateIndex);
    // cout << "result 1 " << result << endl;
    if(result == -1){
        result = binarySearch(nums , target , rotateIndex + 1 , nums.size() - 1);
    }

    return result;
}


int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    // vector<int> nums = {1};
    auto result = search(nums , 0);

    // vector<int> data = {1, 2 , 3,4};
    // int result = binarySearch(data , 0 , 0 , data.size() - 1);
    cout << result << endl;
    return 0;
}