#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int calHashValue(int first , int second){
    int hash = 0;
    if(first >= second){
        hash = 10 * second + first;
    }else{
        hash = 10 * first + second;
    }
    return hash;
}

int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    unordered_map<int, int> pairs;
    for(vector<int> &item : dominoes){
        const int hash = calHashValue(item[0], item[1]);
        if(pairs.find(hash) == pairs.end()){
            pairs[hash] = 1;
        }else{
            pairs[hash] = pairs[hash] + 1;
        }//end if
    }//end for each

    int resultCount = 0;
    for(auto &p : pairs){
        const int n = p.second;
        if(n > 1){
            resultCount += ( (n * (n - 1)) / 2);
        }
    }//end for each
    return resultCount;
}

int main(){
    //[[1,2],[1,2],[1,1],[1,2],[2,2]]
    // vector<vector<int>> dominoes = {{1,2},{1,2},{1,1},{1,2},{2,2}};
    vector<vector<int>> dominoes = {{1,2},{2,1},{3,4},{5,6}};
    auto result = numEquivDominoPairs(dominoes);
    std::cout << "result = " << result << std::endl;
    return 0;
}



