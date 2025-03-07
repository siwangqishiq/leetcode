
#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &nums){
    cout << "[";
    for(auto &v : nums){
        cout << v << " ";
    }
    cout << "]";
    cout << endl;
}

int abs(int a, int b){
    return a >= b? (a- b) : (b-a);
}

bool subsetsAddedIsBeauti(vector<int>& subsets , int addElement, int k){
    for(int &v : subsets){
        if(abs(addElement, v) == k){
            return false;
        }
    }
    return true;
}

void traceSets(vector<int> &subsets,vector<int>& nums,int k,int index , int &total){
    if(index >= nums.size()){
        return;
    }

    //not added
    traceSets(subsets, nums, k, index + 1 , total);
    int added = nums[index];

    //added
    bool isBeauti = subsetsAddedIsBeauti(subsets , added , k);
    if(isBeauti){
        total++;
    }else{
        return;
    }

    subsets.push_back(added);
    // print(subsets);
    traceSets(subsets, nums, k, index + 1 , total);
    subsets.pop_back();
}

int beautifulSubsets(vector<int>& nums, int k) {
    if(nums.empty()){
        return 0;
    }
    
    vector<int> subsets;
    int total = 0;
    traceSets(subsets , nums, k, 0 , total);
    return total;    
}

int main(){
    vector<int> nums = {2,4,6,8};
    int k = 2;
    // vector<int> nums = {1};
    // int k = 1;
    auto result = beautifulSubsets(nums , k);
    cout << "beautifulSubsets result : " << result << std::endl;
    return 0;
}



