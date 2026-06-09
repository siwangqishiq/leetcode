#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> result;
    
    map<int, vector<int>> tempMap;
    for(int i = 0 ; i < temperatures.size() ; i++) {
        int temperature = temperatures[i];

        if(tempMap.find(temperature) == tempMap.end()) {
            tempMap[temperature] = vector<int>{};
        }

        tempMap[temperature].push_back(i);
    }//end for i


    for(auto &p: tempMap) {
        std::cout << p.first << " -> ";
        for(int v : p.second) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

    return result;        
}


int main(){
    vector<int> temperatures = {73,74,75,71,69,72,76,73};

    auto resultList = dailyTemperatures(temperatures);

    for(int v : resultList) {
        cout << v << "\t";
    }//end for each
    std::cout << std::endl;
    
    return 0;
}

