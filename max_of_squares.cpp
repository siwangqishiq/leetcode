#include <iostream>
#include <string>
#include <vector>

using namespace std;

void fillNums(vector<int> &nums, int C){
    int index = 0;
    int candi[] = {9,8,7,6,5,4,3,2,1,0};
    int candiSize = sizeof(candi) / sizeof(int);    
    
    // std::cout << "nums size = " << nums.size() <<std::endl;
    while(index < nums.size()){
        // std::cout << "C = " << C  << std::endl;
        for(int i = 0 ; i < candiSize; i++){
            if(C >= candi[i]){
                C = C - candi[i];
                nums[index] = candi[i];
                break;
            }
        }//end for i

        index++;
    }//end while
}

string maxSumOfSquares(int num, int sum) {
    if(num <= 0 || sum <= 0){
        return "";
    }

    string result = "";

    int index = 0;
    int candi[] = {9,8,7,6,5,4,3,2,1,0};
    int candiSize = sizeof(candi) / sizeof(int);    
    int C = sum;

    while(index < num){
        // std::cout << "C = " << C  << std::endl;
        for(int i = 0 ; i < candiSize; i++){
            if(C >= candi[i]){
                C = C - candi[i];
                // nums[index] = candi[i];
                result += std::to_string(candi[i]);
                break;
            }
        }//end for i
        index++;
    }//end while

    if(C != 0){
        return "";
    }

    return result;
}

int main(){
    int num = 2, sum = 17;
    auto result = maxSumOfSquares(num, sum);
    std::cout << "max sum: " << result << std::endl; 
    return 0;
}
