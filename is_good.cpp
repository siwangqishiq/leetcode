#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> generateBaseN(int n){
    // std::cout << "n = " << n  << std::endl;
    vector<int> baseN(n + 1);

    for(int i = 1; i <= n ;i++){
        baseN[i - 1] = i;
    }
    baseN[n] = n;
    return std::move(baseN);
}

bool isGood(vector<int>& nums) {
    if(nums.empty()){
        return false;
    }
    std::sort(nums.begin(), nums.end());

    auto baseN = generateBaseN(nums.back());
    
    if(baseN.size() != nums.size()){
        return false;
    }

    for(int i = 0,len = baseN.size(); i < len; i++){
        if(baseN[i] != nums[i]){
            return false;
        }
    }//end for i

    return true;
}


int main(){
    vector<int> nums = {1, 3, 3, 2};
    auto result = isGood(nums);
    std::cout << "result :" << result << std::endl;
    return 0;
}