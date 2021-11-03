
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> elem_type;

void combine(vector<elem_type> &e1 , vector<elem_type> &e2 , vector<elem_type> &result){
    result.clear();
    for(elem_type &e : e1){
        for(elem_type &e_sub : e2){
            elem_type r(e.begin() , e.end());
            r.insert(r.end() , e_sub.begin() , e_sub.end());
            result.push_back(r);
        }//end for each e2
    }// end for each e1
}

void print(vector<elem_type> &result){
    for(elem_type e : result){
        for(int &v : e){
            cout << v << "  ";
        }
        cout << endl;
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    if(candidates.empty())
        return result;

    return result;
}

int main(){
    vector<elem_type> e1 = {{1,2}, {3,4} , {9,10} ,{11}};
    vector<elem_type> e2 = {{5,6} , {7,8}};
    vector<elem_type> e3;
    combine(e1 , e2 , e3);
    print(e3);
    return 0;
}




