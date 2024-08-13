

#include <iostream>
#include <vector>

using namespace std;

long long numberOfRightTriangles(vector<vector<int>> &grid){
    const int m = grid.size();
    const int n = grid[0].size();

    long long triCount = 0; 
    vector<int> records;
    vector<vector<int>> colNoneZeros(n);
    for(int i = 0 ; i < m; i++){
        vector<int> &data = grid[i];
        
        records.clear();
        for(int j = 0; j < n; j++){
            if(data[j] == 1){
                records.push_back(j);
                colNoneZeros[j].push_back(i);
            }
        }//end for j

        const int recordSize = records.size();
        if(recordSize < 2) {
            continue;
        }

        for(int index = 0;index < recordSize;index++){
            int col = records[index];
            vector<int> &colRecords = colNoneZeros[col];

            for(int k;k < colRecords.size(); k++){
                if(colRecords[k] == i){
                    continue;
                }
                //add left count
                triCount += index;
                //add right count
                triCount += (records.size() - index - 1);
            }//end for indexColum
        }//end for index
    }//end for i

    return triCount;
}

int main(){
    vector<vector<int>> grid = {
        {1,1,1},
        {1,0,1}
    };

    // vector<vector<int>> grid = {
    //     {1,0,0,0},
    //     {0,1,0,1},
    //     {1,0,0,0}
    // };

    //  vector<vector<int>> grid = {
    //     {1,0,1,0},
    //     {1,0,0,0},
    //     {1,0,0,0}
    // };

    auto result = numberOfRightTriangles(grid);

    cout << "result = " << result << endl;

    return 0;
}

