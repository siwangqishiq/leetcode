#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinRmFromLeft(vector<int>& nums, int k){
    int count = 0;

    int index = 0;
    int min = nums[index];
    int max = nums[nums.size() - 1];
    while(max > min * k){
        index++;
        min = nums[index];
        count++;
    }//end while
    return count;
}

int findMinRmFromRight(vector<int>& nums, int k){
    int count = 0;

    int min = nums[0];
    int index = nums.size() - 1;
    int max = nums[index];
    while(max > min * k){
        index--;
        max = nums[index];
        count++;
    }//end while
    return count;
}


int findMinRm(vector<int>& nums, int k){
    int count = 0;
    int left = 0;
    int right = nums.size() - 1;

    int min = nums[left];
    int max = nums[right];

    while(max > min * k){
        int leftDelta = (nums[left + 1] - nums[left]) * k;
        int rightDelta = nums[right] - nums[right -1];

        if(leftDelta >= rightDelta){
            left++;
        }else{
            right--;
        }//end if
        min = nums[left];
        max = nums[right];

        count++;
    }//end while
    return count;
}

int minRemoval(vector<int>& nums, int k) {
    if(nums.empty() || nums.size() == 1){
        return 0;
    }

    std::sort(nums.begin(), nums.end());
    return findMinRm(nums,k);
}

int main(){
    // vector<int> nums = {1,6,2,9};
    // int k = 3;
    // vector<int> nums = {4,6};
    // int k = 2;
    // vector<int> nums = {32,607,740,134,944,91,410,155,493,89,12};
    // int k = 10;

    vector<int> nums = {8,99,65,16,39};// {8,16,39,65,99}
    int k = 3;

    auto result = minRemoval(nums, k);
    std::cout << "result = " << result << std::endl;
    return 0;
}