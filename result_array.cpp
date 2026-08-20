#include <iostream>
#include <vector>

using namespace std;

vector<int> resultArray(vector<int>& nums) {
    vector<int> result;
    if(nums.size() <= 2){
        return nums;
    }

    vector<int> arr1;
    arr1.push_back(nums[0]);

    vector<int> arr2;
    arr2.push_back(nums[1]);

    for(int i = 2; i < nums.size() ; i++){
        if(arr1[arr1.size() - 1] > arr2[arr2.size() - 1]){
            arr1.push_back(nums[i]);
        }else{
            arr2.push_back(nums[i]);
        }
    }//end for i
    

    for(auto v : arr1){
        result.push_back(v);
    }
    for(auto v : arr2) {
        result.push_back(v);
    }

    return result;        
}

int main(){
    // vector<int> nums = {5, 4, 3, 8};
    vector<int> nums = {2 , 1, 3};
    auto result = resultArray(nums);
    for(auto &v : result) {
        std::cout << v << " ";
    }//end for each
    std::cout << std::endl;
    return 0;
}
