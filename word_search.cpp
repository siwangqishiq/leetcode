#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。
 * 如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，
其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
同一个单元格内的字母不允许被重复使用。
 * 
 * @param board 
 * @param word 
 * @return true 
 * @return false 
 */

void clearVisitedBoard(vector<vector<char>> &visited){
    for(auto &rows : visited){
        for(auto &v : rows){
            v = 0;
        }
    }//end for each
}

bool check(vector<vector<char>>& board , 
            int i, int j , 
            int k , string &word , 
            vector<vector<char>> &visited){
    // cout << "k = " << k << " i,j = " << i << "," << j << " visited[i][j] = " << ((int)visited[i][j]) << endl;

    if(visited[i][j] == 1){
        return false;
    }

    visited[i][j] = 1;
    if(board[i][j] == word[k]){ 
        if(k + 1 >= word.size()){
            visited[i][j] = 0;
            return true;
        }else{
            const int m = visited.size();
            const int n = visited[0].size();
            
            bool ret = false;
            if(i - 1 >= 0){
                ret = check(board, i - 1, j, k + 1, word, visited);
            }
            if(ret){
                return true;
            }
            if(i + 1 < m){
                ret = check(board, i + 1, j, k + 1, word, visited);
            }
            if(ret){
                return true;
            }
            if(j - 1 >= 0){
                ret = check(board, i, j - 1, k + 1, word, visited);
            }
            if(ret){
                return true;
            }
            if(j + 1 < n){
                ret = check(board, i, j + 1, k + 1, word, visited);
            }
            if(ret){
                return true;
            }
            visited[i][j] = 0;
            return false;
        }
    }else{
        visited[i][j] = 0;
        return false;
    }
}

bool exist(vector<vector<char>>& board, string word) {
    const int m = board.size();
    const int n = board[0].size();

    vector<vector<char>> visited(m);
    for(int i = 0 ; i < m ;i++){
        visited[i] = vector<char>(n);
    }
    clearVisitedBoard(visited);
    
    for(int i = 0 ;i < m; i++){
        for(int j = 0 ; j < n; j++){
            if(check(board, i , j , 0, word, visited)){
                return true;
            }
        }//end for j
    }//end for i
    return false;
}

int main(){
    vector<vector<char>> board = 
        {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'},
        };
    std::string word = "ABCB";
    auto result = exist(board , word);
    cout << "exist : " << result << endl;
    return 0;
}