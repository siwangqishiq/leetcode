/**
 * @file find_intersect_values.cpp
 * 
 * https://leetcode.cn/problems/find-common-elements-between-two-arrays/description/
 * 
 * 
 * 给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，它们分别含有 n 和 m 个元素。请你计算以下两个数值：

answer1：使得 nums1[i] 在 nums2 中出现的下标 i 的数量。
answer2：使得 nums2[i] 在 nums1 中出现的下标 i 的数量。
返回 [answer1, answer2]。

 

示例 1：

输入：nums1 = [2,3,2], nums2 = [1,2]

输出：[2,1]

解释：



示例 2：

输入：nums1 = [4,3,2,3,1], nums2 = [2,2,5,2,3,6]

输出：[3,4]

解释：

nums1 中下标在 1，2，3 的元素在 nums2 中也存在。所以 answer1 为 3。

nums2 中下标在 0，1，3，4 的元素在 nums1 中也存在。所以 answer2 为 4。

示例 3：

输入：nums1 = [3,4,2,3], nums2 = [1,5]

输出：[0,0]

解释：

nums1 和 nums2 中没有相同的数字，所以答案是 [0,0]。

 

提示：

n == nums1.length
m == nums2.length
1 <= n, m <= 100
1 <= nums1[i], nums2[i] <= 100
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findIntersect(vector<int> &pats,vector<int> &nums){
    unordered_map<int, int> countMap;
    for(int v : nums){
        countMap[v] = 1;
    }

    int count = 0;
    for(int i = 0 ; i < pats.size(); i++){
        if(countMap.find(pats[i]) != countMap.end()){
            count++;
        }
    }//end for i
    return count;
}


vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result(2);
    result[0] = findIntersect(nums1 , nums2);
    result[1] = findIntersect(nums2 , nums1);
    return result;
}


int main(){

    vector<int> nums1 = {3,4,2,3};
    vector<int> nums2 = {1,5};

    cout << findIntersect(nums1 , nums2) << endl;
    cout << findIntersect(nums2 , nums1) << endl;
    return 0;
}

