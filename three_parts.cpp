#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canThreePartsEqualSum(vector<int>& arr) {
    if(arr.size() < 3){
        return false;
    }
    
    sort(arr.begin() , arr.end());

    for(int v : arr){
        std::cout << v << std::endl;
    }

    int sumA = 0;
    int sumB = 0;
    int sunC = 0;
    return false;
}

int main(){
    vector<int> arr = {0,2,1,-6,6,-7,9,1,2,0,1};
    auto result = canThreePartsEqualSum(arr);

    std::cout << "result : " << result << std::endl;
}




