#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

void printMat(vector<vector<int>> &mat){
    for(vector<int> &vec : mat){
        for(int v : vec){
            cout <<" \t" << v;
        }
        cout << endl;
    }//end for each
}

vector<int> diagVisitMat(vector<vector<int>>& mat , function<void(int , int)> visitFn){
    const int row = mat.size();
    const int colum = mat[0].size();

    vector<int> result;

    for(int i = colum - 1;i >= 0 ;i--){
        int j = 0;
        int x = i;

        vector<int> dialElements;
        while(j < row && x < colum){
            dialElements.push_back(mat[j][x]);
            if(visitFn != nullptr){
                visitFn(j , x);
            }
            x = x + 1;
            j = j + 1;
        }//end while

        if(visitFn == nullptr){
            sort(dialElements.begin() , dialElements.end());
            result.insert(result.end(), dialElements.begin() , dialElements.end());
        }
    }//end for i
    for(int i = 1; i < row;i++){
        int j = 0;
        int y = i;

        vector<int> dialElements;
        while(j < colum && y < row){
            dialElements.push_back(mat[y][j]);
            if(visitFn != nullptr){
                visitFn(y , j);
            }
            j = j + 1;
            y = y + 1;
        }//end while
        
        if(visitFn == nullptr){
            sort(dialElements.begin() , dialElements.end());
            result.insert(result.end(), dialElements.begin() , dialElements.end());
        }
    }//end for i

    return result;
}

vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    if(mat.empty()){
        return mat;
    }
    
    vector<int> nums = diagVisitMat(mat , nullptr);
    int index = 0;
    diagVisitMat(mat , [&mat , &nums , &index](int i , int j){
        mat[i][j] = nums[index++];
    });
    return mat;
}


int main(){
    vector<vector<int>> mat = {
        {3,3,1,1},
        {2,2,1,2},
        {1,1,1,2}
    }; // 1 1 2 3 ,1 2 3 2, 1 2 1 1
    
    diagonalSort(mat);
    printMat(mat);

    //1 1 1 1
    //1 2 2 2
    //1 2 3 3
    return 0;
}


