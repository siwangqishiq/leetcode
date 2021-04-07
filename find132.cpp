/**
 * 给你一个整数数组 nums ，数组中共有 n 个整数。132 模式的子序列 由三个整数 nums[i]、nums[j] 和 nums[k] 组成，并同时满足：i < j < k 和 nums[i] < nums[k] < nums[j] 。

如果 nums 中存在 132 模式的子序列 ，返回 true ；否则，返回 false 。
 
示例 1：

输入：nums = [1,2,3,4]
输出：false
解释：序列中不存在 132 模式的子序列。
示例 2：

输入：nums = [3,1,4,2]
输出：true
解释：序列中有 1 个 132 模式的子序列： [1, 4, 2] 。
示例 3：

输入：nums = [-1,3,2,0]
输出：true
解释：序列中有 3 个 132 模式的的子序列：[-1, 3, 2]、[-1, 3, 0] 和 [-1, 2, 0] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/132-pattern
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 * */

#include <iostream>
#include <vector>

using namespace std;

bool findParttern(vector<int> &nums , int start , int end , vector<vector<int>> &result){
    int len = end - start + 1;
    if(len <= 0){
        return false;
    }else if(len == 1 || len == 2){
        return false;
    }else{
        bool midIsFind = false;
        
        const int mid = (start + end ) / 2;
        const int midValue = nums[mid];
        //search left
        vector<int> leftResult;
        for(int i = start ; i < mid ; i++){
            if(nums[i] < midValue){
                leftResult.push_back(nums[i]);
            }
        }
        //search right
        vector<int> rightResult;
        for(int i = mid + 1;i<=end;i++){
            if(midValue > nums[i]){
                rightResult.push_back(nums[i]);
            }
        }
        if(!leftResult.empty() && !rightResult.empty()){
            midIsFind = true;

            for(int i = 0 ; i < leftResult.size();i++){
                for(int j = 0;j< rightResult.size();j++){
                    vector<int> v;
                    v.push_back(leftResult[i]);
                    v.push_back(midValue);
                    v.push_back(rightResult[j]);

                    result.push_back(v);
                }//end for j
            }//end for i
        }


        bool leftFind = findParttern(nums , start , mid , result);
        bool rightFind = findParttern(nums , mid , end , result);

        return leftFind || rightFind || midIsFind;
    }
}

bool find132pattern(vector<int>& nums) {
    vector<vector<int>> result;
    bool r = findParttern(nums , 0 , nums.size() - 1 , result);

    cout << "find = " << r << endl;
    for(auto &v : result){
        cout << "[";
        for(auto &i :v){
            cout << " " << i;
        }
        cout << " ]" << endl;
    }

    return r;
}

int main(){
    vector<int> nums ={3,1,4,2};
    // vector<int> nums ={1 , 3 ,4};
    find132pattern(nums);
    return 0;
}


