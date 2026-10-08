#include <iostream>
#include <vector>

using namespace std;

int findMinOper(vector<int> &nums, int target, int left , int right){
      if (target == 0) {
        return 0;
    }

    if (target < 0 || left > right) {
        return -1;
    }

    if (left == right) {
        return target == nums[left] ? 1 : -1;
    }

    int leftResult =
        findMinOper(nums, target - nums[left], left + 1, right);

    int rightResult =
        findMinOper(nums, target - nums[right], left, right - 1);

    if (leftResult != -1) {
        leftResult++;
    }

    if (rightResult != -1) {
        rightResult++;
    }

    if (leftResult == -1) {
        return rightResult;
    }

    if (rightResult == -1) {
        return leftResult;
    }

    return min(leftResult, rightResult);
}

int minOperations(vector<int>& nums, int x) {
    return findMinOper(nums, x , 0, nums.size() - 1);        
}

int main(){
    // vector<int> nums = {1,1,4,2,3};
    // int x = 5;

    // vector<int> nums = {5,6,7,8,9};
    // int x = 4;

    vector<int> nums = {3,2,20,1,1,3};
    int x = 10;

    auto result = minOperations(nums, x);
    std::cout << "result = " << result << std::endl;    
    return 0;
}

