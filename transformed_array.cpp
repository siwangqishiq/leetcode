#include <iostream>
#include <vector>

using namespace std;

int abs(int x){
    return x >= 0? x : -x;
}

int moveAndGet(vector<int> &nums, unsigned int step, int index, bool isRight){
    if(step == 0){
        return nums[index];
    }

    if(isRight){
        index = (index + step) % nums.size();
    }else{ //左移
        int i = 0;
        while(i < step){
            index = index - 1;
            if(index < 0){
                index = nums.size() - 1;
            }
            i++;
        }//end while
    }
    return nums[index];
}

vector<int> constructTransformedArray(vector<int>& nums) {
    vector<int> result(nums.size());
    for(int i = 0 ; i < nums.size(); i++){
        int value = nums[i];
        int resultValue = moveAndGet(nums, abs(value), i, value >= 0);
        result[i] = resultValue;
    }//end for i
    return result;
}

int main(){
    // vector<int> nums = {3,-2,1,1};
    vector<int> nums = {-1,4,-1};
    auto result = constructTransformedArray(nums);
    for(auto &v : result){
        std::cout << v << "  ";
    }
    std::cout << std::endl;
    return 0;
}
