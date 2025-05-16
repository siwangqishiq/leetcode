#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    std::sort(coins.begin(), coins.end() , [](int a,int b){return a - b > 0;});
    for(auto &v : coins){
        cout << v << " ";
    }
    cout << endl;

    int count = 0;
    while(amount > 0){
        int i = 0;
        for(i = 0 ; i < coins.size() ;i++){
            if(amount >= coins[i]){
                cout << "amount : " << coins[i] << endl;
                amount = amount - coins[i];
                count++;
                break;
            }
        }//end for i

        if(i == coins.size()){
            break;
        }
    }//end while
    return amount == 0?count:-1;
}

int main(){
    vector<int> coins = {186,419,83,408};
    int amount = 6249;
    // vector<int> coins = {1};
    // int amount = 0;

    int result = coinChange(coins , amount);
    cout << "result : " << result << endl;
    return 0;
}
