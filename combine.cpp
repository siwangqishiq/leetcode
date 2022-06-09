


#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    
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
