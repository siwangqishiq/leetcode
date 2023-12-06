#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    if(nums.empty()){
        return 0;
    }

    unordered_map<int ,int> dataMap;
    for(int &v : nums){
        dataMap[v] = v;
    }

    vector<int> dataArray;
    for(auto &p : dataMap){
        dataArray.push_back(p.first);
    }

    std::sort(dataArray.begin() , dataArray.end());
    // for(auto &v : dataArray){
    //     std::cout << " " << v; 
    // }//end for
    // std::cout << "\n";

    int longest = -1;
    int predValue = dataArray[0];
    int currentLongest = 1;
    for(int i = 1; i < dataArray.size() ; i++){
        if(predValue + 1 == dataArray[i]){
            currentLongest++;
            predValue = dataArray[i];
            std::cout << "predValue = " << predValue << " currentLongest = " << currentLongest << std::endl;
        }else{
            if(currentLongest >= longest){
                longest = currentLongest;
            }

            predValue = dataArray[i];
            currentLongest = 1;
        }
    }//end for i

    if(currentLongest >= longest){
        longest = currentLongest;
    }
    return longest;
}

int main(){
    vector<int> data = {1,2,0,1};
    cout << longestConsecutive(data) << endl;
    return 0;
}