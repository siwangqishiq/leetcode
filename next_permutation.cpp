/**
 * 实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须 原地 修改，只允许使用额外常数空间。

 

示例 1：

输入：nums = [1,2,3]
输出：[1,3,2]
示例 2：

输入：nums = [3,2,1]
输出：[1,2,3]
示例 3：

输入：nums = [1,1,5]
输出：[1,5,1]
示例 4：

输入：nums = [1]
输出：[1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 * */

#include <iostream>
#include <vector>

using namespace std;

void nextPermutation(vector<int>& nums) {
    if(nums.empty() || nums.size() <= 1)
        return;

    int minIndex = -1;
    for(int i = nums.size() - 2;i>=0; i--){
        if(nums[i] < nums[i + 1]){
            minIndex = i;
            break;
        }
    }//end for i

    int maxIndex = -1;
    if(minIndex >= 0){
        int minValue = nums[minIndex];
        for(int i = nums.size() - 1;i>=0; i--){
            if(minValue < nums[i]){
                maxIndex = i;
                break;
            }
        }//end for i
    }

    //swap
    if(minIndex >= 0 && maxIndex >= 0){

        // cout << "minIndex = " << minIndex << endl;
        // cout << "minIndex Value = " << nums[minIndex] << endl;

        // cout << "maxIndex = " << maxIndex << endl;
        // cout << "maxIndex Value = " << nums[maxIndex] << endl;

        int tmp = nums[minIndex];
        nums[minIndex] = nums[maxIndex];
        nums[maxIndex] = tmp;
    }

    // for(int &v : nums){
    //     cout << v << " ";
    // }
    // cout << endl;

    //reverse
    const int mid = (minIndex + nums.size()) / 2;
    //cout << "mid = " << mid << endl;
    for(int i = minIndex + 1; i <= mid;i++){
        //cout << "swap " << i << " with " << (nums.size() - i + minIndex) << endl;

        int tmp = nums[i];
        nums[i] = nums[nums.size() - i + minIndex];
        nums[nums.size() - i + minIndex] = tmp;
    }
}

int main(){
    vector<int> num={1,3,2};
    // vector<int> num={6,5,4,3,2,1};

    nextPermutation(num);

    for(int &v : num){
        cout << v << " ";
    }
    cout << endl;

    return 0;
}