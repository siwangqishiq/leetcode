/**
 * @file harshad_number.cpp
 * @brief 
 * @version 0.1
 * @date 2024-07-03
 * https://leetcode.cn/problems/harshad-number/description/?envType=daily-question&envId=2024-07-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <unordered_map>

using namespace std;

int calHarshaNumber(int number){
    int result = 0;
    while(number != 0){
        int value = number / 10;
        int weightValue = number - 10 * value;
        result += weightValue;
        number = number / 10;
    }//end while

    return result;
}

void buildCache(unordered_map<int , int> &cache){
    for(int i = 0 ; i < 101 ; i++){
        cache[i] = calHarshaNumber(i);
    }
}


int sumOfTheDigitsOfHarshadNumber(int x) {
    unordered_map<int , int> cache;
    buildCache(cache);

    int harsha = cache[x];
    if(x % harsha == 0){
        return harsha;
    }
    return -1;
}


int main(){
    cout << sumOfTheDigitsOfHarshadNumber(18) << endl;
    return 0;
}
