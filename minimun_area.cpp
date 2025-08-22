#include <iostream>
#include <vector>

using namespace std;

int minimumArea(vector<vector<int>>& grid) {
    const int H = grid.size();
    const int W = grid[0].size();

    int left = W + 1;
    int right = 0;
    int top = H + 1;
    int bottom = 0;

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(grid[i][j] == 1){
                // i --- top / bottom
                if(i < top){
                    top = i;
                }

                if(i > bottom){
                    bottom = i;
                }

                // j --- left / right

                if(j < left){
                    left = j;
                }

                if(j > right){
                    right = j;
                }
            }
        }//end for j
    }//end for i

    // cout << "left : " << left << " right : " << right << endl;
    // cout << "top : " << top << " bottom : " << bottom << endl;

    const int width = right - left + 1;
    const int height = bottom - top  + 1;
    const int area = width * height;
    
    return area>0?area:0;
}

int main(){
    vector<vector<int>> grid = {
        {0,1,0},
        {1,1,1},
        {1,1,0}
    };
    auto result = minimumArea(grid);
    cout << "minimun Area : " << result << endl;
    return 0;
}

