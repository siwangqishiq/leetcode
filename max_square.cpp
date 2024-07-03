/**
 * @file max_square.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-03
 * 
 * @copyright Copyright (c) 2024
 * 
 * https://leetcode.cn/problems/maximal-square/description/?envType=problem-list-v2&envId=2cktkvj
 * 
 */


#include <iostream>
#include <vector>
#include <map>

using namespace std;

int calCacheKey(int i , int j){
    return 4000 * i + j;
}

int searchMaxSquare(vector<vector<char>> &matrix,const int i ,const int j , map<int, int> &cache){
    // if(cache.find(calCacheKey(i,j)) != cache.end()){
    //     cout << "hit cache " << i << " , " << j << "  -> " <<cache[calCacheKey(i,j)] << endl; 
    //     return cache[calCacheKey(i,j)];
    // }

    int startY = i + 1;
    int startX = j + 1;

    const int ROW = matrix.size();
    const int COL = matrix[0].size();
    
    int square = 1;
    bool needBreak = false;
    while(startX < COL && startY < ROW){
        needBreak = false;
        //check
        for(int m = i; m <= startY; m++){
            if(matrix[m][startX]== '0'){
                needBreak  = true;
                break;
            }
        }//end for m
        
        if(needBreak){
            break;
        }

        for(int n = j; n <= startX; n++){
            if(matrix[startY][n]== '0'){
                needBreak  = true;
                break;
            }
        }//end for n

        if(needBreak){
            break;
        }

        square = (startX - j + 1) * (startY - i + 1);

        startX = startX + 1;
        startY = startY + 1;
    }//end while
    // cout << "squre = " << square << endl;

    // for(int m = i;m <= startY;m++){
    //     for(int n = j; n <= startX ;n++){
    //         cache[calCacheKey(m , n)] = square;
    //     }//end for n
    // }//end for m
    return square;
}

int maximalSquare(vector<vector<char>>& matrix) {
    const int ROW = matrix.size();
    const int COL = matrix[0].size();
    int maxSquare = 0;

    map<int, int> cache;

    for(int i = 0 ; i < ROW; i++){
        for(int j = 0 ; j < COL ;j++){
            char ch = matrix[i][j];
            if(ch == '1'){
                int square = searchMaxSquare(matrix, i , j , cache);
                if(maxSquare < square){
                    maxSquare = square;
                    if(maxSquare == ROW * COL){
                        return maxSquare;
                    }
                }
            }
        }
    }//end for i
    return maxSquare;
}

int main(){
    // vector<vector<char>> matrix = {
    //     {'1','0','1','0','0'},
    //     {'1','0','1','1','1'},
    //     {'1','1','1','1','1'},
    //     {'1','0','0','1','0'}
    // };
    // vector<vector<char>> matrix = {
    //     {'1','1','1'},
    //     {'1','0','1'},
    //     {'1','1','1'},
    // };

    vector<vector<char>> matrix = {
        {'0','0','0','1'},
        {'1','1','0','1'},
        {'1','1','1','1'},
        {'0','1','1','1'},
        {'0','1','1','1'}
    };
    auto result = maximalSquare(matrix);
    cout << "result = " << result << endl;
    return 0;
}



