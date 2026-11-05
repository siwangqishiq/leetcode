#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int abs(int v){
    return v >= 0? v : -v;
}

int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d){
    unordered_map<int, int> distanceMap;
    int distanceValue = 0;

    for(int i = 0 ; i < arr1.size() ;i++){
        const int value = arr1[i];
        if(distanceMap.find(value) != distanceMap.end()){
            distanceValue += distanceMap[value];
            continue;
        }
        
        int count = 0;
        bool flag = true;
        for(int j = 0 ; j < arr2.size() ; j++){
            if(abs(value - arr2[j]) <= d){
                flag = false;
                break;
            }
        }//end for j
        
        distanceMap[value] = flag?1:0;        
        distanceValue += distanceMap[value];
    }//end for i
    
    // for(auto &p : distanceMap){
    //     std::cout << p.first << " -> " << p.second << std::endl;
    // }
    return distanceValue;
}

int main() {
    vector<int> arr1 = {-3,-3,4,-1,-10};
    vector<int> arr2 = {7,10};
    int d = 12;
    auto result = findTheDistanceValue(arr1 , arr2 , d);
    std::cout << "result = " << result  << std::endl;
    return 0;
}




