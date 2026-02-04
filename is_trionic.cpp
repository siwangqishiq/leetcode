#include <iostream>
#include <vector>

using namespace std;

bool isTrionic(vector<int>& nums) {
    if(nums.size() < 3){
        return false;
    }

    int index = 1;
    int judgeStep = 1;
    int p = -1;
    int q = -1;
    while(index < nums.size()){
        if(judgeStep == 1){ //递增
            if(nums[index - 1] < nums[index]){
                index++;
            }else{
                judgeStep = 2;
                p = index - 1;
            }
        }else if(judgeStep == 2){
            if(nums[index - 1] > nums[index]){
                index++;
            }else{
                judgeStep = 3;
                q = index - 1;
            }
        }else if(judgeStep == 3){
            if(nums[index - 1] < nums[index]){
                index++;
            }else{
                break;
            }
        }//end if
    }//end while

    // std::cout << "index = " << index << "  judgeStep = " << judgeStep << std::endl;
    // std::cout << "p = " << p << "  q = " << q << std::endl;
    return index == nums.size() 
            && judgeStep == 3 
            && p >0 && p < q && q < nums.size() - 1;
}

int main(){
    // vector<int> nums = {1,3,5,4,2,6};
    // vector<int> nums = {2,4,3,3};
    vector<int> nums = {2,1,3};

    auto result = isTrionic(nums);
    std::string output = result?"true":"false";
    std::cout << "result = " << output << std::endl;
}
