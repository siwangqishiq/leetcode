

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double trimMean(vector<int>& arr) {
    if(arr.size() <= 0){
        return 0.0f;
    }

    sort(arr.begin() , arr.end());
    int limitSize = arr.size() * (0.05f);

    double sum = 0.0f;
    int count = 0;
    int index = 0;
    while(index < arr.size()){
        if(index >= limitSize && index < arr.size() - limitSize){
            sum += arr[index];
            count++;
        }
        index++;
    }//end while

    if(count == 0){
        return 0.0;
    }
    return sum / count;
}

int main(){
    vector<int> data = {6,0,7,0,7,5,7,8,3,4,0,7,8,1,6,8,1,1,2,4,8,1,9,5,4,3,8,5,10,8,6,6,1,0,6,10,8,2,3,4};
    cout << trimMean(data) << endl;
    return 0;
}

