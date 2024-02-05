

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findUnsortedSubarray(vector<int>& nums) {
    vector<int> soredNums(nums.begin() , nums.end());
    sort(soredNums.begin() , soredNums.end());

    int left = 0;
    int right = nums.size() - 1;

    while(left < nums.size()){
        if(nums[left] != soredNums[left]){
            break;
        }
        left++;
    }

    while(right >= 0){
        if(nums[right] != soredNums[right]){
            break;
        }
        right--;
    }    

    return left < right?(right - left + 1):0;
}

int main(){
    vector<int> nums = {1,2,3,4};
    cout << findUnsortedSubarray(nums) << endl;
    return 0;
}