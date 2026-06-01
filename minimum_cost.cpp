#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int minimumCost(vector<int> &cost){
    if(cost.empty()){
        return 0;
    }

    std::sort(cost.begin(), cost.end(),[](int a,int b){return a - b > 0 ? 1 : 0;});

    int totalCost = 0; 
    int index = 0;
    
    while(index < cost.size()) {
        totalCost += cost[index];
        if(index + 1 < cost.size()) {
            totalCost += cost[index + 1];
        }

        index += 3;
    }//end while
     
    return totalCost;
}


int main(){
    // vector<int> cost = {6,5,7,9,2,2};

    // vector<int> cost = {5,5};
    vector<int> cost = {1,2,3};
    auto result = minimumCost(cost);

    std::cout << "result = " << result << std::endl;
    return 0;
}




