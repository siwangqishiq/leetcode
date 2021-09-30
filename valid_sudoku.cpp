/**
 * 
 * 请你判断一个 9x9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。

注意：

一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-sudoku
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 * */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;



bool isValidSudoku(vector<vector<char>>& board) {
    const int SIZE = 9;

    if(board.empty() || board.size() != SIZE || board[0].size() != SIZE)
        return false;

    unordered_set<char> valueSet;
    
    //check row
    for(int i = 0 ; i < SIZE ;i++){
        valueSet.clear();
        for(int j = 0 ; j < SIZE ;j++){
            char value = board[i][j];
            if(value == '.'){
                continue;
            }

            if(valueSet.find(value) != valueSet.end()){//found
                //cout << "check value " << value << endl;
                return false;
            }

            valueSet.insert(value);
        }//end for j
    }//end for i
    //cout << "check row ok" << endl;

    //check column
    for(int i = 0 ; i < SIZE ;i++){
        valueSet.clear();
        for(int j = 0 ; j < SIZE ;j++){
            char value = board[j][i];
            if(value == '.'){
                continue;
            }

            if(valueSet.find(value) != valueSet.end()){//found
                return false;
            }

            valueSet.insert(value);
        }//end for j
    }//end for i
    //cout << "check column ok" << endl;

    //check 3x3    
    int subSize = SIZE / 3;
    int left = 0;
    int top = 0;

    vector<pair<int , int>> anchors;
    for(left = 0 ; left < SIZE ; left += subSize){
        for(top = 0 ; top < SIZE ; top += subSize){
            pair<int , int> elem = {left , top};
            anchors.push_back(elem);
        }//end for top
    }//end for left

    for(auto &p : anchors){
        //cout << p.first << "  " << p.second << endl;

        valueSet.clear();
        for(int i = p.first ; i < p.first + subSize; i++){
            for(int j = p.second; j < p.second + subSize ;j++){
                char value = board[i][j];
                if(value == '.'){
                    continue;
                }

                if(valueSet.find(value) != valueSet.end()){//found
                    return false;
                }
                valueSet.insert(value);
            }
        }
    }//end for each
    
    return true;
}

int main() {
    vector<vector<char>> board1 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'},
    };

    vector<vector<char>> board2 = {
        {'.','.','.','.','5','.','.','1','.'},
        {'.','4','.','3','.','.','.','.','.'},
        {'.','.','.','.','.','3','.','.','1'},
        {'8','.','.','.','.','.','.','2','.'},
        {'.','.','2','.','7','.','.','.','.'},
        {'.','1','5','.','.','.','.','.','.'},
        {'.','.','.','.','.','2','.','.','.'},
        {'.','2','.','9','.','.','.','.','.'},
        {'.','.','4','.','.','.','.','.','.'}};

    bool result = isValidSudoku(board2);
    cout << "result : " << result << endl;
    return 0;
}
