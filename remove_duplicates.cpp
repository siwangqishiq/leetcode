

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int limit = nums.size();
    for(int i = 1 ; i < limit;i++){
        if(nums[i - 1] == nums[i]){
            for(int swap = i; swap < limit - 1; swap++){
                nums[swap] = nums[swap + 1];
            }//end for swap
            limit--;
            i--;
        }
    }//end for i
    return limit;
}

int main(){
    vector<int> nums = {0,0,0,0,1,1,1,2,2,3,3,4};

    int size = removeDuplicates(nums);

    for(int i= 0; i< size;i++ ){
        cout << nums[i] << "  ";
    }
    cout << endl;

    return 0;
}
