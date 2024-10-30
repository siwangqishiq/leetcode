#include <iostream>
#include <string>

using namespace std;

int chToInt(char ch){
    int resultInt = 0;
    switch(ch){
        case '0':
        resultInt = 0;
        break;
        case '1':
        resultInt = 1;
        break;
        case '2':
        resultInt = 2;
        break;
        case '3':
        resultInt = 3;
        break;
        case '4':
        resultInt = 4;
        break;
        case '5':
        resultInt = 5;
        break;
        case '6':
        resultInt = 6;
        break;
        case '7':
        resultInt = 7;
        break;
        case '8':
        resultInt = 8;
        break;
        case '9':
        resultInt = 9;
        break;
    }//end switch
    return resultInt;
}

bool isOdd(int value){
    return value % 2 == 0;
}

string getSmallestString(string s) {
    const int len = s.length();
    for(int i = 0 ; i < len -1 ;i++){
        int leftValue = chToInt(s[i]);
        int rightValue = chToInt(s[i+1]);
        if(isOdd(leftValue) == isOdd(rightValue) && leftValue > rightValue){
            char tmpCh = s[i + 1];
            s[i + 1] = s[i];
            s[i] = tmpCh;
            break;
        }//end for each
    }//end for i
    return s;        
}

int main(){
    cout << getSmallestString("001") << endl;
    return 0;
}