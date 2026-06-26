#include <iostream>
#include <vector>

using namespace std;

int findMaxValue(vector<int> &list){
    int maxValue = list[0];
    for(int i = 1; i < list.size() ;i++){
        if(list[i] > maxValue) {
            maxValue = list[i];
        }
    }//end for i
    return maxValue;
}

int largestAltitude(vector<int>& gain) {
    int altitude = 0;
    const int size = gain.size();
    vector<int> altitudes(size + 1, 0);
    for(int i = 0 ; i < size ; i++) {
        altitudes[ i + 1] = altitudes[i] + gain[i];
    }//end for i

    return findMaxValue(altitudes);        
}


int main() {
    vector<int> gain = {-4,-3,-2,-1,4,3,2};
    auto result = largestAltitude(gain);
    std::cout << "result = " << result << std::endl;
    return 0;
}
