#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * https://leetcode.cn/problems/sum-of-distances/submissions/720568340/
 * 
 */


long long calculateDistance(int k, int pos, vector<long long> &prefix){
    int n = prefix.size();

    long long left = (long long)pos * k - (k > 0 ? prefix[k - 1] : 0);
    long long right = (prefix[n - 1] - prefix[k]) - (long long)pos * (n - k - 1);

    return left + right;
}

vector<long long> distance(vector<int>& nums) {
    if(nums.empty()){
        return vector<long long>{};
    }

    vector<long long> result(nums.size());
    
    unordered_map<int, vector<int> > numMap;
    unordered_map<int, vector<long long>> prefixMap;
    unordered_map<int, int> subIndexMap;

    for(int i = 0 ; i < nums.size() ; i++){
        auto value = nums[i];
        numMap[value].push_back(i);
        auto &prefixVec = prefixMap[value];
        prefixVec.push_back(i + (prefixVec.empty()?0:prefixVec.back()));
    }//end for i

    for(int i = 0 ; i < nums.size() ; i++){
        int value = nums[i];
        auto &vec = numMap[value];
        auto &prefixVec = prefixMap[value];

        if(vec.size() <= 1){
            result[i] = 0;
        } else {
            int k = lower_bound(vec.begin(), vec.end(), i) - vec.begin();
            result[i] = calculateDistance(k, i, prefixVec);
        }
    }//end for i

    return result;
}


int main(){
    vector<int> nums = {1,3,1,1,2};
    // vector<int> nums ={0,5,3};
    vector<long long> result = distance(nums);
    for(auto &v : result){
        std::cout << v << "  ";
    }
    std::cout << std::endl;
    return 0;
}
