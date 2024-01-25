
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVecs(vector<vector<int>> &data){
    for(auto &vec : data){
        cout << "[ ";
        for(auto &v : vec){
            cout << v << " ";
        }
        cout << "]" << endl;
    }
}

vector<vector<int>> combinationSum(vector<int>& data, int index , int target){
    vector<vector<int>> result;

    if(index < 0){
        return result;
    }

    if(data[index] == target){
        result.push_back({data[index]});
        return result;
    }

    
    return result;
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    
    return result;
}

int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;

    auto result = combinationSum2(candidates , target);
    printVecs(result);
    return 0;
}