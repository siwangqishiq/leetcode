#include <iostream>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    const int size = temperatures.size();
    
    vector<int> result(size,0);
    vector<int> indexStack;
    if(size == 0){
        return vector<int>{};
    }
    
    indexStack.push_back(0);
    for(int i = 1; i < size ;i++) {
        while(!indexStack.empty()) {
            int top = indexStack.back();
            int topTemp = temperatures[top];
            int curTemp = temperatures[i];
        
            if(curTemp <= topTemp) {
                indexStack.push_back(i);
                break;
            } else {
                indexStack.pop_back();
                result[top] = i - top;
                
                if(indexStack.empty()) {
                    indexStack.push_back(i);
                    break;
                }
            }
        }//end while 
    }//end for i
    
    while(!indexStack.empty()){
        int idx = indexStack.back();
        result[idx] = 0;
        indexStack.pop_back();
    }//end while
    
    return result;        
}


int main(){
    // vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> temperatures = {89,62,70,58,47,47,46,76,100,70};

    auto resultList = dailyTemperatures(temperatures);

    for(int v : resultList) {
        cout << v << "  ";
    }//end for each
    std::cout << std::endl;
    
    return 0;
}

