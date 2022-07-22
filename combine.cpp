


#include <iostream>
#include <vector>

using namespace std;

void trace(vector<int> cur,int k,int startIndex,vector<int> &data, vector<vector<int>> &result){
    if(cur.size() >= k){
        result.push_back(cur);
        return;
    }
    
    cout << "last data size : " << data.size() - startIndex << " current size :" << cur.size() << endl;
    if(data.size() - startIndex < k - cur.size()){
        return;
    }

    for(int i = startIndex; i < data.size(); i++){
        cur.push_back(data[i]);
        trace(cur , k , i + 1 , data , result);
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    
    vector<int> data;
    for(int i = 1; i<= n ;i++){
        data.push_back(i);
    }//end for i

    vector<int> cur;
    trace(cur , k , 0 , data , result);
    
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
    auto result = combine(4 , 2);
    printData(result);
    return 0;
}
