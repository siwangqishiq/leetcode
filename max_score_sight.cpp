#include <iostream>
#include <vector>

using namespace std;

int maxScoreSightseeingPair(vector<int>& values) {
    int result = 0;
    const int size = values.size();
    for(int i = 0 ; i < size; i++){
        for(int j = i + 1 ; j < size; j++){
            const int value = values[i] + values[j] + i - j;
            if(value > result){
                result = value;
            }
        }//end for j
    }//end for i
    return result;
}

int main(){
    vector<int> values = {8,1,5,2,6};
    auto result = maxScoreSightseeingPair(values);
    cout << "result = " << result <<endl;
    return 0;
}