#include <iostream>

int commas(int number){
    int count = 0;
    while(number != 0){
        number = number / 1000;
        if(number != 0){
            count++;
        }
    }//end while
    return count;
}

int countCommas(int n){
    if(n <= 0){
        return 0;
    }
    
    int totalCount = 0;
    for(int i = 1; i <= n ;i++){
        totalCount += commas(i);
    }//end for i    
    return totalCount;
}


int main(){
    // std::cout << commas(1000) << std::endl;
    // std::cout << commas(3002) << std::endl;
    // std::cout << commas(200001) << std::endl;
    // std::cout << commas(1200001) << std::endl;
    
    std::cout << countCommas(1002) << std::endl;
    return 0;
}
