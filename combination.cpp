/**
39. 组合总和
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。

candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

对于给定的输入，保证和为 target 的不同组合数少于 150 个。

 

示例 1：

输入：candidates = [2,3,6,7], target = 7
输出：[[2,2,3],[7]]
解释：
2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
7 也是一个候选， 7 = 7 。
仅有这两种组合。
示例 2：

输入: candidates = [2,3,5], target = 8
输出: [[2,2,2,2],[2,3,3],[3,5]]
示例 3：

输入: candidates = [2], target = 1
输出: []
 

提示：

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
candidate 中的每个元素都 互不相同
1 <= target <= 500

https://leetcode.cn/problems/combination-sum/

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//回溯
void backtrace(vector<int>& candidates , int target,int startIndex , 
            vector<int> alreadySet , vector<vector<int>> &result){
    if(target == 0){//find answer
        result.push_back(alreadySet);
        return;
    }else if(target < 0){// no answer quit
        return;
    }else{
        for(int i = startIndex ; i < candidates.size() ;i++){
            int value = candidates[i];
            int newTarget = target - value; 
            vector<int> newAlreadySet = alreadySet;
            newAlreadySet.push_back(value);
            backtrace(candidates , newTarget, i, newAlreadySet , result);
        }//end for i
    }//end if
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    vector<vector<int>> result;

    //排序 从小到大
    std::sort(candidates.begin() , candidates.end());
    
    for(int i = 0 ; i < candidates.size() ;i++){
        int value = candidates[i];
        int newTarget = target - value; 
        vector<int> alreadySet;
        alreadySet.push_back(value);
        backtrace(candidates , newTarget, i, alreadySet , result);
    }//end for i

    return result;
}

void printVec(vector<vector<int>> &data){
    for(auto &vec : data){
        cout << "[ ";
        for(auto &v : vec){
            cout << v << " ";
        }
        cout << "]";
        cout << endl;
    }
}

int main(){
    // vector<vector<int>> data = {{1,2,3} ,{4,5,6} ,{7,8,9}};
    // printVec(data);

    vector<int> candidates = {2,3,5};
    auto result = combinationSum(candidates , 8);
    printVec(result);

    return 0;
}




