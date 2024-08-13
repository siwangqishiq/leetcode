#include <iostream>
#include <vector>

using namespace std;

bool isArraySpecial(vector<int> &nums){
    if(nums.empty()){
        return true;
    }
    
    bool odd = (nums[0] % 2 == 0);
    for(int i = 1;i< nums.size();i++){
        auto value = nums[i];
        bool curOdd = (value % 2 == 0);
        if(curOdd == odd){
            return false;
        }else{
            odd = curOdd;
        }
    }//end for i
    return true;
}


int main(){
    vector<int> nums = {4,3,1,6};
    auto result = isArraySpecial(nums);

    cout << "result = " << result << endl;
    return 0;
}
