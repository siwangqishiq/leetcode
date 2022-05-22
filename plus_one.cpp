#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits){
    int prior = 1;
    bool isEnd = false;
    for(int i = digits.size() -1 ; i >= 0; i--){
        int value = digits[i] + prior;
        if(value >= 10){
            prior = 1;
            value -= 10;
            digits[i] = value;
        }else{
            digits[i] = value;
            isEnd = true;
            break;
        }
    }//end for i

    if(!isEnd && prior != 0){
        vector<int> result = {1};
        result.insert(result.end() , digits.begin() , digits.end());
        return result;
    }
    return digits;
}

int main(){
    vector<int> data = {0};
    auto r = plusOne(data);

    for(auto v : r){
        cout << v << " ";
    }
    cout << endl;
    return 0;
}