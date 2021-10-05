#include <iostream>
#include <vector>

using namespace std;

/**
 * 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-image
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */

void print(vector<vector<int>>& matrix){
    for(auto &arr : matrix){
        for(auto &e : arr){
            cout << e << "\t";
        }//end for each
        cout << endl;
    }//end for each
    cout << endl;
}

void rotate(vector<vector<int>>& matrix) {
    if(matrix.empty())
        return;
    
    int start = 0;
    int end = matrix.size() - 1;

    while(end - start >= 1){
        cout << "start " << start << "  end " << end << endl;

        vector<int> tmpVec;
        for(int i = start ; i <= end ; i++){
            tmpVec.push_back(matrix[start][i]);
        }

        cout << "tmp : \t";
        for(int &v : tmpVec){
            cout << v << "\t";
        }
        cout << endl;

        for(int i = start ; i <= end ; i++){
            int index = i - start;
            matrix[start][end - index] = matrix[start + index][start];
        }//end for i

        for(int i = start ; i <= end ; i++){
            matrix[i][start] = matrix[end][i];
        }//end for i
        
        for(int i = end ; i >= start ;i--){
            int index = end - i;
            matrix[end][start + index] = matrix[end - index][end];
        }//end for i

        for(int i = end; i >= start ; i--){
            int index = end - i;
            matrix[end - index][end] = tmpVec[end - start - index];
        }//end for i
        
        start++;
        end--;
    }//end while
}


int main(){
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    // vector<vector<int>> matrix = {{1,2,3} , {4,5,6},{7,8,9}};
    // vector<vector<int>> matrix = {{1,2} , {3,4}};
    // vector<vector<int>> matrix = {{1}};
    // vector<vector<int>> matrix = {{4,8}, {3,6}};
    print(matrix);
    rotate(matrix);
    print(matrix);
    return 0;
}