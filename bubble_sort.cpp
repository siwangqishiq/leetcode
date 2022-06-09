

#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &data){
    for(int i = 0 ; i < data.size() ; i++){
        for(int j = data.size() - 1 ; j > i ;j--){
            if(data[j] < data[j - 1]){
                int tmp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = tmp;
            }
        }//end for j
    }//end for i
}

int main(){

    vector<int> data = {5,3,8,1,0,8,3,9,7,10,43,3};

    bubbleSort(data);

    for(auto &v : data){
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
