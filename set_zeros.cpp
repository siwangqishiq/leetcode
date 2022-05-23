
#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    const int rowCount = matrix.size();
    const int colCount = matrix[0].size(); 

    vector<int> clearRow;
    vector<int> clearCol;

    for(int i = 0 ; i < rowCount ; i++){
        for(int j = 0 ; j< colCount ;j++){
            if(matrix[i][j] == 0){
                clearRow.push_back(i);
                clearCol.push_back(j);
            }
        }//end for j
    }//end for i

    for(int row : clearRow){
        for(int j = 0 ; j< colCount ;j++){
            matrix[row][j] = 0;
        }//end for j
    }//end for 

    for(int col : clearCol){
        for(int i = 0 ; i< rowCount ;i++){
            matrix[i][col] = 0;
        }//end for j
    }//end for 
}

void printMat(vector<vector<int>> &matrix){
    for(int i = 0 ; i < matrix.size() ; i++){
        for(int j = 0 ; j< matrix[i].size() ;j++){
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }//end for i
}

int main(){
    vector<vector<int>> data = {{1,1,1},{1,0,1},{1,1,1}};
    setZeroes(data);
    printMat(data);
    return 0;
}



