/**
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> buildPermute(vector<int> nums){
    vector<vector<int>> result;
    if(nums.size() == 1){
        vector<int> v;
        v.push_back(nums[0]);
        result.push_back(v);
    }else{
        for(int i = 0 ; i < nums.size();i++){
            int value = nums[i];

            // cout << "value = " << value << endl;

            vector<int> lastNums(nums.begin(), nums.end());
            lastNums.erase(lastNums.begin() + i);

            //   cout << "[";
            // for(int &v : lastNums){
            //     cout << " " << v;
            // }
            // cout << " ]" << endl;

            vector<vector<int>> subResult = buildPermute(lastNums);

            for(vector<int> vec : subResult){
                vector<int> v1(vec.begin() , vec.end());
                v1.push_back(value);
                result.push_back(v1);
            }//end for each


        }//end for i
    }
    return result;
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result = buildPermute(nums);
    return result;
}

int main(){
    vector<int> nums = {1,2,3,4,5,6};

    vector<vector<int>> result = permute(nums);

    for(vector<int> &vec : result){
        cout << "[";
        for(int &v : vec){
            cout << " " << v;
        }
        cout << " ]" << endl;
    }//end for each


    return 0;
}