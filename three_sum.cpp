/**
 * 
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
 * 使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 * */


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>

using namespace std;

string buildString(int a , int b , int c){
    string str = to_string(a);
    str.append(",");
    str.append(to_string(b));
    str.append(",");
    str.append(to_string(c));
    return str;
}

void twoSum(vector<int> &nums ,int sumValue, int begin , unordered_set<string> &set , 
        vector<vector<int>> &result){
    int left = begin;
    int right = nums.size() - 1;

    while(left < right){
        int curSum = nums[left] + nums[right];
        if(curSum == sumValue){
            int a = -sumValue;
            int b = nums[left];
            int c = nums[right];

            left++;
            right--;

            string str = buildString(a , b ,c);
            if(set.find(str) == set.end()){
                vector<int> answer;
                answer.push_back(a);
                answer.push_back(b);
                answer.push_back(c);

                result.push_back(answer);

                set.insert(str);
            }
            
        }else if(curSum < sumValue){
            left++;
        }else{
            right--;
        }
    }//end while
}

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int> > result;
    if(nums.size() <= 2)
        return result;
    
    std::sort(nums.begin() , nums.end());
    unordered_set<string> answerSet;
    int preValue;
    for(int i = 0 ; i < nums.size() - 2;i++){
        int a = nums[i];

        if(i != 0 && nums[i - 1] == a){
            continue;
        }
        twoSum(nums , -a , i + 1, answerSet, result);
        
    }//end for i

    return result;
}

void printV(vector<vector<int>> vv){
    cout << "["<<endl;
    for(auto &rowV : vv){
        cout << "\t [";
        for(auto &e:rowV){
            cout << e << " ,";
        }
        cout << "]" << endl;
    }
    cout << "]"<<endl;
}

int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    auto r = threeSum(nums);
    printV(r);
    return 0;
}