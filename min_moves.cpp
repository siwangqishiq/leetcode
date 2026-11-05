#include <iostream>
#include <vector>

using namespace std;

int minMoves(vector<int>& nums) {
    if(nums.empty()){
        return 0;
    }

    int maxValue = nums[0];
    for(int i = 1; i < nums.size() ;i++){
        if(maxValue < nums[i]){
            maxValue = nums[i];
        }
    } //end for i

    int moveCount = 0;
    for(int i = 0 ; i < nums.size(); i++){
        moveCount += (maxValue - nums[i]);
    }//end for i
    return moveCount;        
}

int main(){
    vector<int> nums = {2,1,3};
    auto result = minMoves(nums);
    std::cout << "result = " << result << std::endl;
    return 0;
}
