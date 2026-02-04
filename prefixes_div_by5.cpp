#include <iostream>
#include <vector>

using namespace std;

vector<bool> prefixesDivBy5(vector<int> &nums){
    const int size = nums.size();
     
    vector<bool> result(size);
    
    int value = 0;
    for(int i = 0; i < size; i++){
        if(nums[i] == 1){
            value += 1;
        }

        //cout << "value :" << value << endl;
        result[i] = (value % 5 == 0)?true:false;
        value = value << 1;
    }//end for i

    return result;
}

int main(){
    vector<int> nums = {0,1,1};
    
    auto result = prefixesDivBy5(nums);
    for(bool v : result){
        cout << v << "  ";
    }//end for each 
    cout << endl;
    return 0;
}
