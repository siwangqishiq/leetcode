/**
40. 组合总和 II
给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用 一次 。

注意：解集不能包含重复的组合。 

 

示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
输出:
[
[1,2,2],
[5]
]

https://leetcode.cn/problems/combination-sum-ii/

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

    vector<int> candidates = {10,1,2,7,6,1,5};
    auto result = combinationSum(candidates , 8);
    printVec(result);

    return 0;
}




