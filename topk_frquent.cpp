

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> result;

    unordered_map<int , int> freqMap;
    for(int &value : nums){
        if(freqMap.find(value) == freqMap.end()){
            freqMap[value] = 1;
        }else{
            freqMap[value]++;
        }
    }//end for i

    vector<pair<int,int>> freqArray;
    for(auto p: freqMap){
        freqArray.push_back(p);
    }//end for each

    std::sort(freqArray.begin() , freqArray.end() , [](pair<int,int> left , pair<int,int> right){
        return left.second > right.second;
    });

    for(int i = 0; i < std::min(k , static_cast<int>(freqArray.size()));i++){
        result.push_back(freqArray[i].first);
    }
    return result;
}

int main(){
    vector<int> data = {1,3,1,1,2,2};
    topKFrequent(data , 2);
    return 0;
}
