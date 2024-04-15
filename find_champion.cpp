
#include <iostream>
#include <vector>

using namespace std;

int findChampion(vector<vector<int>>& grid) {
    const int count = grid.size(); // team 0 ~ count -1
    vector<int> lastVector(count);
    for(int i = 0 ; i < count ; i++){
        lastVector[i] = i;
    }//end for i

    int winner = lastVector[0];
    const int vecLimit = lastVector.size();
    for(int i = 1 ; i < vecLimit ; i++) {
        const int oppon = lastVector[i];
        if(grid[winner][oppon] != 1){
            winner = oppon;
        }
    }//end for i
    return winner;
}

int main(){
    vector<vector<int>> grid = {{0,1},{0,0}};

    int r = findChampion(grid);

    cout << "r = " << r << endl;
    return 0;
}


