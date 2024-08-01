#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minRectanglesToCoverPoints(vector<vector<int>>& points, int w){
    if(points.empty()){
        return 0;
    }

    vector<int> data(points.size());
    for(int i = 0 ; i < points.size();i++){
        data[i] = points[i][0];
    }//end for i

    std::sort(data.begin() , data.end());

    int coverCount = 1;
    int left = data[0];
    for(int i = 1; i < data.size();i++){
        if(left + w < data[i]){
            coverCount++;
            left = data[i];
        } 
    }//end for i
    return coverCount;
}

int minRectanglesToCoverPoints2(vector<vector<int>>& points, int w) {
    if(points.empty()){
        return 0;
    }

    std::sort(points.begin() , points.end() , [](vector<int> left , vector<int> right){
        return !(left[0] - right[0] >= 0);
    });

    // for(auto &v : points){
    //     cout << "{ " << v{0} << " " << v{1} << " }" << " ,";
    // }
    // cout << endl;

    int coverCount = 1;
    int left = points[0][0];
    for(int i = 1; i < points.size();i++){
        vector<int> p = points[i];
        if(left + w < p[0]){
            coverCount++;
            left = p[0];
        } 
    }//end for i
    return coverCount;
}

int main(){
    // vector<vector<int>> points = {{2,1},{1,0},{1,4},{1,8},{3,5},{4,6}};
    // int w = 1;
    // vector<vector<int>> points = {{0,0},{1,1},{2,2},{3,3},{4,4},{5,5}};
    // int w = 2;
    // vector<vector<int>> points = {{2,3},{1,2}};
    // int w = 0;
    vector<vector<int>> points = {{7,13},{1,3},{14,14},{11,3},{3,6},{1,8},{1,11},{16,1},{6,17},{1,13},{17,14},{3,11},{8,8},{8,5},{10,5},{12,4},{9,8},{2,3},{11,4},{1,18}};
    int w = 4;
    cout << "minRectanglesToCoverPoints = " << minRectanglesToCoverPoints(points , w) << endl;
    return 0;
}