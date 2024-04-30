


#include <iostream>
#include <vector>

using namespace std;

// void trace(vector<int> cur,int k,int startIndex,vector<int> &data, vector<vector<int>> &result){
//     if(cur.size() >= k){
//         result.push_back(cur);
//         return;
//     }
    
//     cout << "last data size : " << data.size() - startIndex << " current size :" << cur.size() << endl;
//     if(data.size() - startIndex < k - cur.size()){
//         return;
//     }

//     for(int i = startIndex; i < data.size(); i++){
//         cur.push_back(data[i]);
//         trace(cur , k , i + 1 , data , result);
//     }
// }

void pickElement(vector<int> &curPick ,int index, int n, int k, vector<vector<int>> &result){
    // cout << "index = " << index << endl;
    if(index > n){
        return;
    }

    if(curPick.size() >= k){
        result.push_back(curPick);
        return;
    }

    // vector<int> newPick = curPick;
    curPick.push_back(index + 1);
    pickElement(curPick , index + 1 , n, k , result);

    if(!curPick.empty()){
        curPick.erase(curPick.end() - 1);
    }
    pickElement(curPick , index + 1 , n,  k , result);
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> pick;
    pickElement(pick , 0 , n , k , result);
    return result;
}

void printData(vector<vector<int>> list){
    for(auto v : list){
        for(int e : v){
            cout << e << "\t";
        }//end for each
        cout << endl;
    }//end for each
}

int main(){
    auto result = combine(4, 2);
    printData(result);
    return 0;
}
