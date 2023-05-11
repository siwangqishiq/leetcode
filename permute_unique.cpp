
#include <iostream>
#include <vector>

using namespace std;

void traceRoute(vector<int> &nums ,int index ,vector<int> &currentAnswer , vector<vector<int>> &result){
    if(index >= nums.size()){
        return;
    }else{//trace
        for(int i = index;i< nums.size();i++){
            int value = nums[i];
            auto current = currentAnswer;
            current.push_back(value);
            
            cout << "[";
            for(auto &v : current){
                cout << v << " ";
            }//end for each
            cout << "]" << endl;

            if(current.size() == nums.size()){
                result.push_back(current);
            }else{
                traceRoute(nums , index + 1 , current , result);
            }
            current.erase(nums.begin() + i);
        }//end for i
    }
}


vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    traceRoute(nums , 0 ,current, result);

    return result;
}

void printVec(vector<vector<int>> &data){
    for(auto &vec : data){
        cout << "[";
        for(auto &v : vec){
            cout << v << " ";
        }//end for each
        cout << "]" << endl;
    }//end for each
}


int main(){
    vector<int> nums = {1,2,3};
    auto result = permuteUnique(nums);
    // printVec(result);
    return 0;
}
