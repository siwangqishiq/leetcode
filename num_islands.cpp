/**
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

示例 1：

输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
示例 2：

输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] 的值为 '0' 或 '1'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-islands
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */

#include <iostream>
#include <vector>

using namespace std;

void show(vector<vector<bool>> &records){
    for(vector<bool> &vec : records){
        for(bool v : vec){
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool visit(int i , int j , vector<vector<char>>& grid , vector<vector<bool>> &visitRecords ,bool isNewIsland){
    cout << "visit " << i << " , " << j << "  visitrecodes = "<<visitRecords[i][j] << endl;

    //show(visitRecords);
  
    if(visitRecords[i][j] == true){
        return false;
    }

    visitRecords[i][j] = true;

    if(grid[i][j] == '0')
        return false;

    // //visit up
    if(i - 1 >= 0){
        visit(i - 1 , j , grid , visitRecords , false);
    }
    //visit down
    if(i + 1 < grid.size()){
        visit(i + 1 , j , grid , visitRecords , false);
    }

    //visit left
    if(j - 1 >=0 ){
        visit(i , j - 1 , grid , visitRecords , false);
    }
    //visit right 
    if(j + 1 < grid[0].size()){
        visit(i , j + 1 , grid , visitRecords , false);
    }

    return isNewIsland;
}

void test(vector<vector<bool>> &visitRecords){
    visitRecords[0][0] = true;
}

int numIslands(vector<vector<char>>& grid) {
    vector<vector<bool>> visitRecords;
    for(int i = 0 ; i < grid.size();i++){
        visitRecords.push_back(vector<bool>(grid[i].size() , false));
    }//end for i
    
    int islandNums = 0;
    for(int i = 0 ; i < grid.size();i++){
        for(int j = 0 ; j < grid[i].size();j++){
            if(visit(i , j , grid , visitRecords , true)){
                islandNums++;
            }

        }//end for j
        cout << endl;
    }//end for i
    return islandNums;
}



int main(){
    vector<vector<char>> grid = {
        {'1','1','1','1','1'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'},
    };

    int nums = numIslands(grid);
    cout << "island num = " <<nums << endl;
    return 0;
}