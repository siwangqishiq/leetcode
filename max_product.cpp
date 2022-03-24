#include <iostream>
#include <vector>

using namespace std;

void pushValue(int *array , int value){
    if(value > array[0]) {
        int tmp = array[0];
        array[0] = value;
        array[1] = tmp;
    }else if(value <= array[0] && value > array[1]){
        array[1] = value;
    }
}

int maxProduct(vector<int>& nums) {
    int select[2] = {-1 , -1};

    for(int i = 0 ;i < nums.size() ;i++){
        pushValue(select , nums[i]);
    }//end for i

    return (select[0] - 1) * (select[1] - 1);
}

int main(){
    vector<int> nums = {3,7};
    // int select[2] = {-1 , -1};

    // for(int i = 0 ;i < nums.size() ;i++){
    //     pushValue(select , nums[i]);
    // }//end for i

    // cout << "max: " << select[0] << "  next :" << select[1] << endl;

    auto result = maxProduct(nums);
    cout << "max: " << result << endl;
    return 0;
}






