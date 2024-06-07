#include <iostream>
#include <vector>

using namespace std;

int findSubArrayMaxElement(vector<int> &nums , int start , int end){
    int maxValue = nums[start];
    for(int i = start + 1;i <= end ;i++){
        const int value = nums[i];
        if(maxValue < value){
            maxValue = value;
        }
    }//end for i
    return maxValue;
}

int findSubArrayMinElement(vector<int> &nums , int start , int end){
    int minValue = nums[start];
    for(int i = start + 1;i <= end ;i++){
        const int value = nums[i];
        if(minValue > value){
            minValue = value;
        }
    }//end for i
    return minValue;
}

int lis(int start , int end , vector<int> &nums , vector<vector<int>> &dp){
    if(end == start){
        return 1;
    }

    if(dp[start][end] > 0){
        return dp[start][end];
    }

    cout << start << ", " << end << endl;

    //set dp value
    int value = lis(start, end - 1 , nums , dp);
    dp[start][end] = value + (findSubArrayMaxElement(nums , start , end - 1) < nums[end]?1:0);
    return dp[start][end];
}

int lengthOfLIS(vector<int>& nums) {
    if(nums.empty()){
        return 0;
    }

    const int size = nums.size();
    vector<vector<int>> dp(size , vector<int>(size , 0));
    for(int i = 0 ; i < size ;i++){
        dp[i][i] = 1;
    }
    
    int result = lis(0 , size - 1, nums , dp);

    for(auto &vec : dp){
        for(auto &v : vec){
            cout << v << " ";
        }//end for each
        cout << endl;
    }//end for each
    return result;
}

int main(){
    vector<int> data = {10,9,2,5,3,7,101,18};
    auto r = lengthOfLIS(data);
    cout << "--> " << r << endl;
    return 0;
}