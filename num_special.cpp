#include <iostream>
#include <vector>

using namespace std;

bool checkColumZero(vector<vector<int>>& mat, int rowIndex, int colIndex){
    const int size = mat.size();
    for(int i = 0 ;i < size ; i++){
        if(mat[i][colIndex] == 1 && rowIndex != i){
            return false;
        }
    }
    return true;
}

int numSpecial(vector<vector<int>>& mat) {
    int retCount = 0;
    for(int i = 0 ; i < mat.size() ; i++){
        int specialCol = -1;
        for(int j = 0 ; j < mat[i].size() ; j++){
            if(mat[i][j] == 1){
                specialCol = j;
                break;
            }
        }//end for j

        if(specialCol != -1){
            bool rowErrFlag = false;
            for(int j = specialCol + 1; j< mat[i].size(); j++){
                if(mat[i][j] != 0){
                    rowErrFlag = true;
                    break;
                }
            }//end for j

            if(rowErrFlag){
                continue;
            }

            // std::cout << "special col = " << specialCol << "  i = " << i << std::endl;

            if(checkColumZero(mat, i, specialCol)){
                retCount++;
            }
        }
    }//end for i
    return retCount;
}

int main(){
    vector<vector<int>> mat = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };
    // vector<vector<int>> mat = {
    //     {1,0,0},
    //     {0,0,1},
    //     {1,0,0}
    // };

    //  vector<vector<int>> mat = {
    //     {0,0,0,0,0,0,0,0,0,0},
    //     {0,0,0,0,0,0,0,0,0,0},
    //     {0,0,0,0,0,0,1,0,0,0},
    //     {0,0,0,0,1,0,0,0,0,0},
    //     {0,0,0,0,0,0,0,0,1,0},
    //     {0,0,0,1,0,0,0,0,0,1},
    //     {0,0,0,0,0,0,0,0,0,0},
    //     {0,0,0,0,0,1,0,0,0,0}
    // };

    auto result = numSpecial(mat);
    std::cout << "result = " << result << std::endl;
    return 0;
}

