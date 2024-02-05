
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// const long MIN_VALUE = -99999;

// int findMax(vector<int> &nums , int begin , int end){
//     // cout << "begin :" << begin << "  end: " << end << endl;
//     if(end <= begin){
//         return MIN_VALUE;
//     }
//     if(end - begin == 1){
//         return nums[begin];
//     }

//     int mid = (end + begin) / 2;
//     int leftMaxValue = MIN_VALUE;
//     int rightMaxValue = MIN_VALUE;

//     if(mid - begin >= 1){
//         leftMaxValue = findMax(nums , begin , mid);
//     }
    
//     if(end - mid - 1 >= 1){
//         rightMaxValue = findMax(nums , mid + 1 , end);
//     }

//     int midMaxValue = nums[mid];
//     int currentValue = midMaxValue;
//     for(int i = begin ; i < end ;i++){
//         if(i == mid){
//             continue;
//         }

//         currentValue *= nums[i];
//         if(currentValue > midMaxValue){
//             midMaxValue = currentValue;
//         }
//     }//end for i

//     int max = leftMaxValue;
//     if(max < midMaxValue){
//         max = midMaxValue;
//     }
//     if(max < rightMaxValue){
//         max = rightMaxValue;
//     }

//     cout << "begin :" << begin << "  end: " << end <<"  " << max << endl;
//     return max;
// }


const long MIN_VALUE = -99999;

int multiValue(vector<int> &nums , int begin , int end , unordered_map<int,int> &multiResult){
    const int key = begin * nums.size() + end;
    if(multiResult.find(key) != multiResult.end()){
        return multiResult[key];
    }

    int result = 1;

    for(int i = begin ;i < end ;i++){
        result *= nums[i];
    }//end for i
    multiResult[key] = result;
    
    return result;
}

int maxProduct(vector<int>& nums) {
    int maxValue = MIN_VALUE;

    const int size = nums.size() + 1;
    // vector<vector<int>> multiResult(size , vector<int>(size , MIN_VALUE));
    // cout << "size = " << size << endl;
    unordered_map<int , int> multiResult;

    for(int i = 0; i < nums.size() ; i++){
        for(int j = i + 1; j < nums.size() + 1 ; j++){
            int value = multiValue(nums , i , j , multiResult);
            if(maxValue < value){
                maxValue = value;
            }
        }//end for j
    }//end for i
    return maxValue;    
}

int main(){
    vector<int> nums = {1,2,3,4};
    cout << maxProduct(nums) << endl;
    return 0;
}

