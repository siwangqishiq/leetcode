
#include <iostream>
#include <vector>

using namespace std;

int abs(int value){
    return value >= 0?value :-value;
}

int findClosestNumber(vector<int>& nums) {
    int minDistance = 1000000;
    int minValue;

    for(auto &value : nums){
        int absValue = abs(value);
        if(minDistance >= absValue){
            minDistance = absValue;

            if(abs(minValue) == absValue){
                // std::cout << "minValue = " << minValue << "  value = " << value << std::endl;
                minValue = minValue > value?minValue:value;
            }else{
                minValue = value;
            }
        }
    }//end for each

    return minValue;
}

int main(){
    vector<int> nums = {-4,-2,1,4,8};
    auto result = findClosestNumber(nums);
    cout << "result : " << result << endl; 
    return 0;
}


