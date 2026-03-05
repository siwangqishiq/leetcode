#include <iostream>
#include <string>

using namespace std;


int minOperations(string s){
    if(s.empty()){
        return 0;
    }

    const int size = s.size();
    string sOdd = s;
    string sEven = s;

    for(int i= 0; i < size ; i++){
        if(i % 2 == 0){
            sOdd[i] = '1';
            sEven[i] = '0';
        }else{
            sOdd[i] = '0';
            sEven[i] = '1';
        }
    }//end for i

    // std::cout << sOdd << std::endl;
    // std::cout << sEven << std::endl;

    int oddCounter = 0;
    int eveCounter = 0;

    for(int i = 0 ; i < size ; i++){
        if(sOdd[i] != s[i]){
            oddCounter++;
        }

        if(sEven[i] != s[i]){
            eveCounter++;
        }
    }//end for i

    return oddCounter <= eveCounter?oddCounter:eveCounter;
}

int main(){
    // auto result = minOperations("0100");
    // auto result = minOperations("10");
    auto result = minOperations("1111");
    std::cout << "result = " << result << std::endl;
    return 0;
}
