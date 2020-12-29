
/**
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，
 * 判断 nums 中是否存在四个元素 a，b，c 和 d ，
 * 使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

string buildStringFromInts(int a , int b , int c , int d){
    string sb;
    sb+= a;
    sb+=",";
    sb+= b;
    sb+=",";
    sb+= c;
    sb+=",";
    sb+= d;
    return sb;
}

void threeSum(vector<int> &nums ,int a, int target , int begin , vector<vector<int>> &result , 
            unordered_set<string> &set){
    for(int i = begin ;i < nums.size() - 2;i++){
        int b = nums[i];

        if(i != begin && nums[i] == nums[i - 1]){
            continue;
        }

        int left = i + 1;
        int right = nums.size() - 1;

        while(left < right){
            int value = b + nums[left] + nums[right];
            if(value == target){
                string intStr = buildStringFromInts(a , b , nums[left] , nums[right]);
                if(set.find(intStr) == set.end()){
                    vector<int> r = {a , b , nums[left] , nums[right]};
                    result.push_back(r);

                    set.insert(intStr);
                }
                
                left++;
                right--;
            }else if(value < target){
                left++;
            }else if(value > target){
                right--;
            }
        }//end while
    }//end for i
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;

    if(nums.size() < 4){
        return result;
    }

    sort(nums.begin() , nums.end());

    unordered_set<string> set;

    for(int i = 0 ; i < nums.size() - 3;i++){
        int a = nums[i];

        if(i != 0 && nums[i] == nums[i - 1]){
            continue;
        }

        threeSum(nums , a , target - a , i+1 , result , set);
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
    vector<int> nums = {-2,-1,-1,1,1,2,2};
    
    printV(fourSum(nums , 0));
    return 0;
}