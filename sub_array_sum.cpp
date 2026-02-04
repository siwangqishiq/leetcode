#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    vector<int> prefixNums(nums.size());
    int sumValue = 0;
    
    for(int i = 0 ;i < nums.size(); i++){
        sumValue += nums[i];
        prefixNums[i] = sumValue;
    }//end for i

    int counter = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    for(int i= 0; i < nums.size() ; i++){
        int value = nums[i];
        int lastValue = k - value;

        std::cout << "lastValue " << lastValue << std::endl;
        for(auto &p : mp){
            std::cout << p.first << "  ";
        }//end for each
        std::cout << std::endl;
        
        if(mp.find(lastValue) != mp.end()){
            counter++;
        }
        mp[prefixNums[i]] = 1;
    }//end for i
    return counter;
}


int main(){
    // vector<int> nums = {1,2,3};
    // int k = 3;

    vector<int> nums = {1,2,1,2,1};
    int k = 3;

    auto result = subarraySum(nums, k);

    cout << "result = " << result << endl;
    return 0;
}