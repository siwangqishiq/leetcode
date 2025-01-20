#include <iostream>
#include <vector>

using namespace std;


void printResult(vector<vector<int>> &result){
    for(auto &list : result){
        for(auto &v : list){
            cout << v << "\t";
        }//end for each
        cout << endl;
    }
}


vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    const int rowCount = img.size();
    const int colCount = img[0].size();

    vector<vector<int>> result(rowCount, vector<int>(colCount,0));
    for(int i = 0 ; i < rowCount; i++){
        for(int j = 0 ; j < colCount ;j++){
            int sumValue = img[i][j];
            int sumCount = 1;
            if(i - 1 >= 0 && j - 1 >= 0){
                sumValue += img[i-1][j-1];
                sumCount++;
            }

            if(i - 1 >= 0){
                sumValue += img[i - 1][j];
                sumCount++;
            }

            if(i - 1 >= 0 && j + 1 < colCount){
                sumValue += img[i - 1][j + 1];
                sumCount++;
            }

            if( j - 1 >= 0){
                sumValue += img[i][j - 1];
                sumCount++;
            }

            if(j + 1 < colCount){
                sumValue += img[i][j + 1];
                sumCount++;
            }

            if( i + 1 < rowCount && j - 1 >= 0){
                sumValue += img[i + 1][j - 1];
                sumCount++;
            }

            if(i + 1 < rowCount){
                sumValue += img[i + 1][j];
                sumCount++;
            }

            if(i + 1 < rowCount && j + 1 < colCount){
                sumValue += img[i + 1][j + 1];
                sumCount++;
            }

            result[i][j] = sumValue / sumCount;
        }//end for j
    }//end for each
    return result;
}

int main(){
    // vector<vector<int>> img = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> img = {{100,200,100},{200,50,200},{100,200,100}};
    auto result = imageSmoother(img);
    printResult(result);
    return 0;
}



