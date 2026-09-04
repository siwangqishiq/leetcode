#include <iostream>
#include <vector>

using namespace std;


vector<int> buildMinArray(vector<int> &nums){
    const int size = nums.size();
    vector<int> minArray(size);
    
    int minValue = 1000000001;
    for(int i = size - 1; i >= 0 ; i--){
        if(nums[i] < minValue){
            minValue = nums[i];
        }

        minArray[i] = minValue;
    }
    return minArray;
}


int firstStableIndex(vector<int>& nums, int k) {
    if(nums.empty()){
        return -1;
    }

    const int size = nums.size();
    
    int max = nums[0];
    int min = nums[size - 1];
    
    int index = -1;
    int minStableValue = 1000000001;
    
    vector<int> minArr = buildMinArray(nums);
        
    for(int i = 0; i < size; i++){
        // find the max
        if(nums[i] >= max){
            max = nums[i];
        }

        //find the min
        min = minArr[i];        
     
        int stableValue = max - min;
        if (stableValue <= k) {
            return i;
        }
    }//end for i
     
    return index;        
}

int main(){
    vector<int> nums = {6, 1 ,4};
    int k = 5;
    auto result = firstStableIndex(nums, k);
    std::cout << "result = " << result << std::endl;
    return 0;
}


