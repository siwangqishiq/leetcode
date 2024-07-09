#include <iostream>
#include <vector>

using namespace std;


/**
 * @brief 
 * 
 * @param nums 
 * @return int
 * 
 * dp[i][j]  if   j - i == 0 return nums[i]
 *           else if j - i == 1 return max(nums[i] , nums[j])
 *           else j - i > 1 : dp[i][j - 1] + num[j] , dp[i][j - 3] + num[j - 1]  j 
 *             
 *  
 * {1,2,3,1}
 * 
 * f(0) = 1
 * f(1) = 2
 * f(2) = 4
 * 
 * f(3) = max(f(1) + nums[3] , f(0) + nums[2]) = max(2 + 1 , 1 + 3) = 4
 * 
 * ...
 * 
 * f(n) = max(f(n - 2) + nums[n] , f(n - 3) + nums[n - 1]) 
 * 
 * f(3) = max(f(1) + nums[3] , f(0) + nums[2])
 * 
 */

int max(int a , int b){
    return a >= b?a:b;
}

int rob(vector<int>& nums){
    if(nums.empty()){
        return 0;
    }

    const int size = nums.size();
    vector<int> data(size);
    for(int i = 0 ; i < size; i++){
        if(i == 0){
            data[i] = nums[i];
        }else if(i == 1){
            data[i] = max(nums[i - 1] , nums[i]);
        }else if(i == 2){
            data[i] = max(nums[i -2] + nums[i] , nums[i - 1]);
        }else{
            data[i] = max(data[i - 2] + nums[i] , data[i - 3] + nums[i - 1]);
        }
    }//end for i

    return data[size - 1];
}


int main(){
    vector<int> nums = {1,2,3,4};
    // vector<int> nums = {2,1,1,2};
    auto result = rob(nums);
    cout << result << endl;
    return 0;
}



