#include <iostream>
#include <vector>

using namespace std;

int abs(int a, int b){
    int ret = a - b;
    return ret >= 0 ?ret:-ret;
}

int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int count = 0;

    for(int i = 0 ; i < arr.size() - 3;i++){
        if(abs(arr[i] - arr[i + 1]) <= a
            && abs(arr[i + 1] - arr[i + 2]) <= b
            && abs(arr[i] - arr[i + 2]) <= c){
            count++;
        }
    }//end for i

    return count;
}

int main(){
    vector<int> arr ={3,0,1,1,9,7};
    int a = 7;
    int b = 2;
    int c = 3;
    auto result = countGoodTriplets(arr , a , b ,c);
    cout << "result = " << result << std::endl;
    return 0;
}




