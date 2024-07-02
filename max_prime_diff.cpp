

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrimer(int num){
    if(num == 1){
        return false;
    }
    int limit = (int)sqrt(num);
    for(int i = 2;i <= limit;i++){
        if(num % i == 0){
            return false;
        }
    }//end for i
    return true;
}


int maximumPrimeDifference(vector<int>& nums) {
    int left = 0;
    for(int i = 0 ; i < nums.size();i++){
        if(isPrimer(nums[i])){
            left = i;
            break;
        }
    }

    int right = 0;
    for(int i = nums.size() - 1 ; i >= 0;i--){
        if(isPrimer(nums[i])){
            right = i;
            break;
        }
    }
    return right - left;
}

int main(){
    vector<int> nums = {1,7};
    int result = maximumPrimeDifference(nums);
    cout << result << endl;
    return 0;
}

