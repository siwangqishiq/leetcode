#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int mod_pow(int a, int b, int c) {
    int result = 1;
    a = a % c;  // 初始值取模，防止 a 大于 c
    
    while (b > 0) {
        // 如果 b 是奇数，将当前的 a 乘入结果
        if (b % 2 == 1) {
            result = (result * a) % c;
        }
        // b 是偶数，更新 a 和 b
        a = (a * a) % c;
        b = b / 2;
    }
    
    return result;
}

int powLong(int left , int right){
    int result = 1;
    for(int i = 0 ; i < right;i++){
        result *= left;
    }//end for i
    return result;
}

vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
    vector<int> result;

    for(int i = 0 ; i < variables.size();i++){
        auto item = variables[i];
        int value = mod_pow(mod_pow(item[0], item[1], 10) , item[2] , item[3]);
        if(value == target){
            result.push_back(i);
        }
    }//end for i
    return result;
}

int main(){
    vector<vector<int>> variables = {{2,3,3,10},{3,3,3,1},{6,1,1,4}};
    vector<int> result = getGoodIndices(variables , 2);
    cout << "result: " ;
    for(auto &v : result){
        cout << v << " ";
    }
    cout << endl;
    return 0;
}