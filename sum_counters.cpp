#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subArraySumSquares(vector<int> &nums, int start, int end){
    // std::cout << "[ " << start << "  " << end << " ]" << std::endl;
    unordered_map<int, int> numMap;
    for(int i = start; i < end ; i++){
        numMap[nums[i]] = 1;
    }//end for i
    return numMap.size() * numMap.size();
}

int sumCounts(vector<int>& nums) {
    if(nums.empty()){
        return 0;
    }

    int squareSum = 0;
    for(int i= 0; i <= nums.size() ; i++){
        for(int j = i + 1; j <= nums.size() ; j++){
            squareSum = squareSum + subArraySumSquares(nums, i, j);
        }//end for j
    }//end for i
    return squareSum;
}

int main(){
    vector<int> nums = {2,2};
    auto result = sumCounts(nums);

    std::cout << "result = " << result << std::endl;
    return 0;
}