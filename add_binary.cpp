

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string addBinary(string a, string b) {
    string left;
    string right;

    if(a.length() >= b.length()){
        left = a;
        right = b;
    }else{
        left = b;
        right = a;
    }

    string result = "";
    int leftIndex = left.length() -1;
    int prior = 0;
    bool overflow = false;
    for(int i = right.length() - 1 ; i >= 0; i--, leftIndex--){
        char leftValue = left[leftIndex];  
        char rightValue = right[i];

        if(prior > 0){
            if(leftValue == '0'){
                leftValue = '1';
            }else if(rightValue == '0'){
                rightValue = '1';
            }else if(leftValue == '1' && rightValue == '1'){
                overflow = true;
            }
        }
        
        if(leftValue == '0' && rightValue == '0'){ // 0 + 0
            result = "0" + result;
            prior = 0;
        }else if(leftValue == '0' && rightValue == '1'){
            result = "1" + result;
            prior = 0;
        }else if(leftValue == '1' && rightValue == '0'){
            result = "1" + result;
            prior = 0;
        }else if(leftValue == '1' && rightValue == '1'){
            result = (overflow?"1":"0") + result;
            prior = 1;
        }

        overflow = false;
    }//end for i

    while(leftIndex >= 0){
        char leftValue = left[leftIndex];
        if(leftValue == '0'){
            if(prior == 0){
                result = '0' + result;
            }else{
                result = '1' + result;
            }

            prior = 0;
        }else if(leftValue == '1'){
            if(prior == 0){
                result = '1' + result;
                prior = 0;
            }else{
                result = '0' + result;
                prior = 1;
            }
        }

        leftIndex--;
    }

    if(prior > 0){
        result = "1" + result;
    }

    return result;
}


int main(){
    cout << addBinary("1" , "1") << endl;
    return 0;
}
