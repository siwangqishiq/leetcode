
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    if(numRows <= 0){
        return result;
    }

    vector<int> first = {1};
    result.push_back(first);
    for(int i = 2 ; i <= numRows;i++){
        vector<int> tailVec = *(result.end() - 1);
        vector<int> nextLine(tailVec.size() + 1);
        for(int j = 0 ; j < tailVec.size() + 1 ; j++){
            if(j == 0){
                nextLine[j] = tailVec[0];
            }else if(j == tailVec.size()){
                nextLine[j] = tailVec[tailVec.size() - 1];
            }else{
                nextLine[j] = tailVec[j - 1] + tailVec[j];
            }
        }//end for j
        result.push_back(nextLine);
    }
    return result;
}

int main(){
    return 0;
}

