#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> getSneakyNumbers(vector<int>& nums) {
    unordered_map<int, int> records;
    for(auto &v : nums){
        if(records.find(v) == records.end()){
            records[v] = 1;
        }else{
            int counter = records[v];
            records[v] = counter + 1;
        }        
    } //end for each

    vector<int> result;
    for(auto &p : records){
        if(p.second == 2){
            result.push_back(p.first);
        }
    }//end for each
    return result;
}


int main(){
    vector<int> nums = {7,1,5,4,3,4,6,0,9,5,8,2};

    auto ret = getSneakyNumbers(nums);

    std::cout << "result : ";

    for(auto &v : ret){
        std::cout << v << "  ";
    }
    std::cout << std::endl;

    return 0;
}
