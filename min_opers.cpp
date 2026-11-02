#include <vector>
#include <iostream>

using namespace std;

int minOperations(vector<int>& nums) {
    if(nums.size() <= 1){
        return 0;
    }

    const int size = nums.size();
    vector<int> arrows(size, 0);

    for(int i = 1 ; i < nums.size(); i++){
        arrows[i] = (nums[i] > nums[i - 1])?1:-1;    
    }//end for i

    int polarPointCount = 0;
    int preValue = arrows[1];
    int polarPos = -1;
    for(int i = 1; i < arrows.size() ; i++){
        if(preValue != arrows[i]){
            polarPointCount++;
            polarPos = i;
        }
        preValue = arrows[i];
    }//end for i

    std::cout << "polarPointCount = " << polarPointCount << std::endl;
    std::cout << "polarPos = " << polarPos << std::endl;

    if(polarPointCount > 1){
        return -1;
    }
    return 0;
}

int main() {
    vector<int> nums = {0,2,1};
    auto result = minOperations(nums);
    std::cout << "result = " << result << std::endl;
    return 0;
}