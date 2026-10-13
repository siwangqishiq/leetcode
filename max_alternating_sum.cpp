#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int abs(int num){
    return num >= 0? num:-num;
}

long long maxAlternatingSum(vector<int>& nums) {
    if(nums.empty()){
        return 0;
    }

    vector<int> absNums(nums.size());
    for(int i = 0 ; i < nums.size(); i++){
        absNums[i] = abs(nums[i]);
    }

    std::sort(absNums.begin(), absNums.end());

    long long maxSum = 0;
    long long maxMinus = 0;

    int mid = absNums.size() / 2;

    for(int i = 0 ; i< mid ; i++){
        maxMinus += absNums[i] * absNums[i];
    }

    for(int i = mid; i < absNums.size(); i++){
        maxSum += absNums[i] * absNums[i];
    }//end for i

    return maxSum - maxMinus;
}

int main(){
    vector<int> nums = {1,2,3};
    auto result = maxAlternatingSum(nums);
    std::cout << "result = " << result << std::endl;
    return 0;
}


