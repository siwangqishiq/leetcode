
#include <iostream>
#include <vector>

using namespace std;

int divToMovOp(int value , int b){
    int move = 0;
    int k = 0;
    
    int count = 1;
    while(count < b){
        move++;
        count = count << 1;
    }//end while

    if(count > b){
        count = count >> 1;
        k = b - count;
    }

    cout << "move = " << move << " sub = " << k << endl;
    return (value >> move) - k * b;
}

vector<int> productExceptSelf(vector<int>& nums) {
    int allMuti = 1;
    for(auto &v : nums){
        allMuti = allMuti * v;
    }

    vector<int> result(nums.size());
    for(int i = 0 ; i < nums.size();i++){
        if(nums[i] == 0){
            int mutliValue = 1;
            for(int j = 0 ; j < nums.size();j++){
                if(i == j){
                    continue;
                }else{
                    mutliValue = mutliValue * nums[j];
                }
            }
            result[i] = mutliValue;
        }else{
            result[i] = allMuti / nums[i];
        }
    }//end for i
    return result;
}


int main(){
    cout << divToMovOp(100,3) << endl;
    return 0;
}