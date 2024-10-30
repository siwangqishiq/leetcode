#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isSpecial(int number){
    if(number <= 10){
        return true;
    }

    unordered_map<int , int> valueMap;
    while(number != 0){
        int nextNumber = number / 10;
        int weightValue = number - (nextNumber) * 10 ;

        if(valueMap.find(weightValue) != valueMap.end()){
            return false;
        }

        valueMap[weightValue] = 1;
        number = nextNumber;
    }//end while

    return true;
}

int countSpecialNumbers(int n){
    int count = 0;
    for(int i = 1 ; i <= n ; i++){
        if(isSpecial(i)){
            count++;
        }
    }//end for i
    return count;
}

int main(){
    int value = 765560;
    cout << "countSpecialNumbers(" << value << ") = "
        << countSpecialNumbers(value) << endl;


    // cout << isSpecial(123) << endl;
    return 0;
}