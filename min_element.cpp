#include <iostream>
#include <vector>

using namespace std;

int calNumSumValue(int num){
    int sum = 0;

    while(num != 0){
        int weightValue = num % 10;
        num = num / 10;
        
        sum += weightValue;
    }//end while

    return sum;
}

int minElement(vector<int> &nums){
    if(nums.empty()) {
        return 0;
    }
    
    int min = 10001;
    for(int num : nums){
        int sumValue = calNumSumValue(num);
        if(min > sumValue){
            min = sumValue;
        }
    }
    return min;
}


int main() {
    // int v = calNumSumValue(4);
    // std::cout << v << std::endl;

    vector<int> nums = {999, 19, 199};
    auto result = minElement(nums);

    std::cout << "result = " << result << std::endl;

    return 0;
}
