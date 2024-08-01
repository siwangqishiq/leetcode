#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxmiumScore(vector<int>& cards, int cnt) {
    if(cnt <= 0){
        return 0;
    }

    sort(cards.begin() , cards.end());
    int accumlate = 0;

    int index = cards.size() - 1;
    int count = 0;
    int left;
    while(index >= 0 || count < cnt){
        count++;
        accumlate = accumlate + cards[index];
        index--;
    }//end while
    
    return accumlate;
}

int main(){
    vector<int> cards = {1,2,8,9};
    int cnt = 3;
    auto result = maxmiumScore(cards , cnt);
    cout << "result : " << result << endl;
    return 0;
}