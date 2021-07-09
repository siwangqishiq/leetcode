#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int majorityElement(vector<int>& nums) {
    if(nums.empty()){
        return -1;
    }

    unordered_map<int , int> countMap;

    for(int &value : nums){
        if(countMap.find(value) == countMap.end()){
            countMap[value] = 1;
        }else{
            int count = countMap[value];
            countMap[value] = count + 1;
        }
    }//end for each

    //find first
    int maxCount = -1;
    int maxValue = -1;
    for(auto p : countMap){
        //cout << p.first << " = " << p.second << endl;
        if(maxCount < p.second){
            maxCount = p.second;
            maxValue = p.first;
        }
    }//end for each

    return maxCount >= (nums.size() / 2 + 1)? maxValue : -1;
}

int main(){
    vector<int> nums = {2,2,1,1,1,2,2};
    int r = majorityElement(nums);
    cout << "majority element = " << r << endl;
    return 0;
}