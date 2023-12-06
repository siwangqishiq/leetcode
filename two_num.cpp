#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

// vector<int> twoSum(vector<int>& nums, int target) {
//     vector<int> result = {0 , 0};
//     const int LEN = nums.size();
//     if(LEN <= 1){
//         return result;
//     }

//     for(int i = 0 ; i < LEN ; i++){
//         const int oneNum = nums[i];
//         for(int j = i + 1 ; j < LEN ; j++){
//             if(oneNum + nums[j] == target){
//                 result[0] = i;
//                 result[1] = j;
//                 return result;
//             }
//         }//end for j
//     }//end for i

//     return result;
// }

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result = {0 , 0};
    const int LEN = nums.size();
    if(LEN <= 1){
        return result;
    }

    unordered_map<int , int> numMap;
    for(int i = 0 ;  i < LEN ;i++){
        numMap[nums[i]] = i;
    }//end for i

    for(int i = 0 ; i < LEN ; i++){
        const int oneNum = nums[i];
        int desireValue = target - oneNum;

        if(numMap.find(desireValue) != numMap.end()){
            int pos = numMap[desireValue];
            if(pos != i){
                result[0] = i;
                result[1] = pos;
                return result;
            }
        }
    }//end for i
    return result;
}

int main(){
    vector<int> nums= {2,7,11,15};
    auto result = twoSum(nums , 26 );
    cout << "[" << result[0] << " " << result[1] << endl;
    return 0;
}


