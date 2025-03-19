
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void printVecArray(vector<vector<int>> &data){
    for(auto &vec : data){
        cout << "[ ";
        for(auto &v : vec){
            cout << v << " ";
        }//end for each
        cout << " ]" << endl;
    }//end for each
}

void printMap(std::map<int,int> &map){
    for(auto &p : map){
        cout << p.first << " : " << p.second << endl;
    }//end for each
}


vector<vector<int>> findMatrix(vector<int>& nums) {
    std::map<int,int> numsCountMap;
    int charMaxCount = 0;
    for(auto &v : nums){
        if(numsCountMap.find(v) == numsCountMap.end()){
            numsCountMap[v] = 1;
        }else{
            numsCountMap[v] = (numsCountMap[v] + 1);
        }

        if(numsCountMap[v] > charMaxCount){
            charMaxCount = numsCountMap[v];
        }
    }//end for each

    // printMap(numsCountMap);
    // cout << "charMaxCount = " << charMaxCount << endl;
    vector<vector<int> > result;
    int index = charMaxCount;
    while(index > 0){
        vector<int> selected;
        for(auto &p : numsCountMap){
            if(p.second > 0){
                p.second--;
                selected.push_back(p.first);
            }
        }//end for each
        result.push_back(selected);
        index--;
    }//end while

    return result;
}


int main(){
    // vector<int> nums = {1,3,4,1,2,3,1};
    vector<int> nums = {1,2,3,4};
    auto result = findMatrix(nums);
    printVecArray(result);

    return 0;
}


