/***
 * 
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。
 * 找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
示例：

输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 

提示：

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest
 * 
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int threeSumClosest(vector<int> &nums, int target) {
    if(nums.size() < 3){
        return 0;
    }

    int absClosestValue = 999999999;
    int result = 0;

    sort(nums.begin(),nums.end());

    for(int i = 0; i < nums.size() - 2;i++){
        int c = nums[i];

        int left = i+1;
        int right = nums.size() - 1;

        while(left < right){
            int sumValue = c + nums[left] + nums[right];
            int absSumValue = abs(sumValue - target);

            if(absSumValue < absClosestValue){
                absClosestValue = absSumValue;
                result = sumValue;
            }

            if(sumValue == target){
                return sumValue;
            }else if(sumValue > target){
                right--;
            }else if(sumValue < target){
                left++;
            }
        }//end while
    }//end for i
    return result;
}

int main(){
    //vector<int> nums = {-1,2,1,-4};
    vector<int> nums = {0,2,1,-3};
    int val = threeSumClosest(nums , 1);

    cout << val << endl;
    return 0;
}