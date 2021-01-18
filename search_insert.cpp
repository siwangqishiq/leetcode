#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int> &nums , int target){
    if(nums.empty())
        return 0;

    int left = 0;
    int right = nums.size();

    int lastMid = -1;
    int mid = -2;

    while(left < right){
        lastMid = mid;
        mid = (left + right) / 2;

        if(lastMid == mid){
            return nums[mid] > target? mid : mid + 1;
        }

        int value = nums[mid];

        //cout << "mid = " << mid << endl;
        if(value == target){
            return mid;
        }else if(target < value){
            right = mid;
        }else{
            left = mid;
        }
    }//end while

    return nums[mid] > target? mid : mid + 1;
}


int main(){
    vector<int> nums = {1};
    cout << searchInsert(nums , 2) << endl;

    return 0;
}