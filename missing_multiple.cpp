#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int missingMultiple(vector<int>& nums, int k) {
    unordered_map<int, bool> numMap;
    for(auto &v : nums){
        numMap[v] = true;
    }

    int i = 1;
    while(i <= 10000){
        int value = i * k;
        if(numMap.find(value) == numMap.end()){
            return value;
        }
        i++;
    }//end while
    return 0;
}

int main(){
    vector<int> nums = {1,4,7,10,15};
    int k = 5;

    std::cout << "missing multiple : " << missingMultiple(nums, k) << std::endl;
    return 0;
}