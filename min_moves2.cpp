#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int abs(int v){
    return v>=0? v: -v;
}

int minMoves2(vector<int> &nums){
    std::sort(nums.begin(), nums.end());

    const int size = nums.size();
    const int midValue = nums[size/2];

    int sum = 0;
    for(int i = 0 ; i < size ;i++){
        sum += abs(nums[i] - midValue);
    }//end for i

    return sum;
}

int main() {
    // vector<int> nums = {1,10,2,9};
    vector<int> nums = {1,2,3};
    auto result = minMoves2(nums);
    std::cout << "result = " << result << std::endl;
    return 0;
}


