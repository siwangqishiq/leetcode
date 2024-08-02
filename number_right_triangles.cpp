

#include <iostream>
#include <vector>

using namespace std;

long long numberOfRightTriangles(vector<vector<int>> &grid){
    const int m = grid.size();
    const int n = grid[0].size();

    long long triCount = 0; 
    
    for(int i = 0 ; i < m; i++){
        vector<int> &data = grid[i];
        
        vector<int> records;
        for(int j = 0; j < n; j++){
            if(data[j] == 1){
                records.push_back(j);
            }
        }//end for j

        if(records.size() < 2) {
            continue;
        }

        for(auto &col : records) {
            for(int k = 0 ; k < m; k++){
                if(k == i){
                    continue;
                }

                if(grid[k][col] == 1){
                    triCount++;
                }
            }//end for k
        }//end for k
    }//end for i

    return triCount;
}

int main(){
    vector<vector<int>> grid = {
        {1,0,1},
        {1,0,0},
        {1,0,0}
    };

    auto result = numberOfRightTriangles(grid);

    cout << "result = " << result << endl;

    return 0;
}

