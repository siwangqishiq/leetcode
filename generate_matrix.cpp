/**
 * 
 * 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

 

示例 1：


输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
示例 2：

输入：n = 1
输出：[[1]]
 

提示：

1 <= n <= 20

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */

#include <iostream>
#include <vector>

using namespace std;

enum Move{
    move_right,
    move_down,
    move_left,
    move_up
};

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result;

    const int size = n;
    int data[size][size];
    
    int left = -1;
    int top = 0;

    int index = 1;
    const int end = n * n;
    Move mode = move_right;

    int rightLimit = n - 1;
    int downLimit = n - 1;
    int leftLimit = 0;
    int uplimit = 1;

    while(index <= end){
        //update position
        //cout << "mode " << mode << endl;
        switch(mode){
            case move_left:
            left--;
            if(left <= leftLimit){
                leftLimit++;
                mode = move_up;
            }
            break;

            case move_right:
            left++;
            if(left >= rightLimit){
                rightLimit--;
                mode = move_down;
            }
            break;

            case move_up:
            top--;
            if(top <= uplimit){
                uplimit++;
                mode = move_right;
            }
            break;

            case move_down:
            top++;
            if(top >= downLimit){
                downLimit--;
                mode = move_left;
            }
            break;
        }//end switch

        //cout << "top - left : " << top << " " << left << "  value = " << index << endl;

        data[top][left] = index;
        index++;
    }//end while

    for(int i= 0 ;i < n ;i++){
        vector<int> row;
        for(int j = 0 ; j < n ;j++){
            row.push_back(data[i][j]);
        }
        result.push_back(row);
    }

    return result;
}

void print(vector<vector<int>> &list){
    for(vector<int> &row : list){
        for(int &v : row){
            cout << "\t" << v;
        }
        cout << endl;
    }
} 

int main(){
    //vector<vector<int>> result = {{1,2,3} , {4,5,6} ,{7,8,9}};
    //print(result);

    auto r = generateMatrix(1);
    print(r);
    return 0;
}



