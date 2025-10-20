#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int finalValueAfterOperations(vector<string>& operations) {
    int result = 0;
    for(auto &op : operations){
        if(op == "X++" || op == "++X"){
            result++;
        }else if(op == "X--" || op == "--X"){
            result--;
        }
    }//end for
    return result;
}

int main(){
    
    return 0;
}