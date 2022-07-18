


// 给出一个区间的集合，请合并所有重叠的区间。

// 示例 1:

// 输入: [[1,3],[2,6],[8,10],[15,18]]
// 输出: [[1,6],[8,10],[15,18]]
// 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 示例 2:

// 输入: [[1,4],[4,5]]
// 输出: [[1,5]]
// 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> &left , vector<int> right){
    return left[0] < right[0];
}

/**
*
[[a,b]] [leftElem,rightElem]
**/
void mergeAdd(vector<vector<int>> &result , vector<int> &addElem){
    if(result.empty()){
        result.push_back(addElem);
    }else{
        vector<int> lastElem = result[result.size() - 1];
        
        int addLeft = addElem[0];
        int addRight = addElem[1];

        if(addLeft > lastElem[1]){
            result.push_back(addElem);
        }else{
            result[result.size() - 1][1] = std::max(result[result.size() - 1][1] , addRight);
        }
    }
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end() , compare);

    vector<vector<int>> result;
    for(auto &v : intervals){
        mergeAdd(result , v);
    }//end for

    return result;
}

int main(){
    // vector<vector<int>> intervals = {{1,3},{15,18},{2,6},{8,10}};
    vector<vector<int>> intervals = {{1,4},{4,5}};
    auto result = merge(intervals);

    for(auto &v : result){
        cout << "[ " << v[0] << " , " << v[1] << "] ";
    }//end for each
    cout << endl;

    return 0;
}