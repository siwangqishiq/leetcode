#include <iostream>
#include <vector>

using namespace std;

bool check(int i, int j ,vector<vector<int>>& grid, int row, int col){
    int value = grid[i][j];
    if(i + 1 < row && value != grid[i + 1][j]){
        return false;
    }

    if(j + 1 < col && value == grid[i][j + 1]){
        return false;
    }
    
    return true;
}

bool satisfiesConditions(vector<vector<int>>& grid) {
    const int row = grid.size();
    const int col = grid[0].size();

    for(int i = 0 ; i < row; i++){
        for(int j = 0; j < col ; j++){
            if(!check(i, j , grid , row , col)){
                return false;
            }
        }//end for j
    }//end for i
    return true;
}



int main(){
    return 0;
}