#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

int interSetCount(unordered_map<int,bool> &aSet, unordered_map<int,bool> &bSet){
    int count = 0;
    for(auto &p : aSet){
        if(bSet.find(p.first) != bSet.end()){
            count++;
        }
    }//end for each
    return count;
}

vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    if(A.empty()){
        return vector<int>{};
    }
    
    const int size = A.size();

    vector<int> result(size);
    
    unordered_map<int,bool> aSet;
    unordered_map<int,bool> bSet;

    for(int i = 0; i < size ; i++){
        aSet[A[i]] = true;
        bSet[B[i]] = true;
        const int intersectionCount = interSetCount(aSet, bSet);
        result[i] = intersectionCount;
    }//end for i
    return result;
}


int main(){
    vector<int> A = {2,3,1};
    vector<int> B = {3,1,2};

    auto result = findThePrefixCommonArray(A, B);
    for(auto v : result) {
        std::cout << v << "  ";
    }
    std::cout << std::endl;
    return 0;
}
