#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> targetIndices(vector<int>& nums, int target) {
    vector<int> indices;
    std::sort(nums.begin(), nums.end());
    bool isFoundTarget = false;

    for(int i = 0 ; i < nums.size() ; i++){
        if(target == nums[i]){
            indices.push_back(i);
            isFoundTarget = true;
        }else{
            if(isFoundTarget){
                break;
            }
        }
    }//end for i

    return indices;
}

int main(){
    vector<int> nums = {1,2,5,2,3};
    int target = 3;

    auto indices = targetIndices(nums, target);
    for(auto i : indices) {
        std::cout << i << "  ";
    }
    std::cout << std::endl;
    return 0;
}
