
#include <iostream>
#include <vector>

using namespace std;

vector<int> findRange(vector<int> &nums , int value, int pos){
    vector<int> result;
    result.push_back(pos);
    result.push_back(pos);

    for(int i = pos;i>=0;i--){
        if(nums[i] == value){
            result[0] = i;
        }else{
            break;
        }
    }//end for i

    for(int i = pos;i < nums.size();i++){
        if(nums[i] == value){
            result[1] = i;
        }else{
            break;
        }
    }//end for i

    return result;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result = {-1 , -1};
    if(nums.empty())
        return result;

    int left = 0;
    int right = nums.size();
    int mid = -1;
    int lastMid = -2;
    while(left < right){
        lastMid = mid;
        
        mid = (left + right) / 2;
        
        if(lastMid == mid){
            return result;
        }

        int value = nums[mid];
        if(target == value){
            return findRange(nums , target , mid);
        }else if(target > value){
            left = mid;
        }else{
            right = mid;
        }
    }//end while

    return result;
}

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    vector<int> result = searchRange(nums , 6);
    cout << "[ " << result[0] << " , " << result[1] << " ]" << endl;

    return 0;
}
