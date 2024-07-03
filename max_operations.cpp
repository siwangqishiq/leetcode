
#include <iostream>
#include <vector>

using namespace std;

int maxOperations(vector<int>& nums) {
    if(nums.size() < 2){
        return 0;
    }
    
    int count = 0;
    int addResult = 0;
    bool hasResult = false;
    for(int i = 0;i < nums.size() - 1; i = i + 2){
        auto first = nums[i];
        auto second = nums[i + 1];
        const auto currentResult = first + second;
        // cout << "currentResult -> " << currentResult << endl;
        if(hasResult && addResult != currentResult){
            break;
        }else{
           addResult = currentResult;
           hasResult = true;
        }//end if
        count++;
    }//end for i
    return count;    
}

int main(){
    vector<int> data = {3,2,6,1,4};
    cout << "result : " << maxOperations(data) << endl;
    return 0;
}



