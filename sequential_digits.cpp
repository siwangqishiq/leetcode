#include <iostream>
#include <vector>

using namespace std;

vector<long> buildSeq(){
    vector<long> seqs = {
        12,23,34,45,56,67,78,89,
        123,234,345,456,567,678,789,
        1234,2345,3456,4567,5678,6789,
        12345,23456,34567,45678,56789,
        123456,234567,345678,456789,
        1234567,2345678,3456789,
        12345678,23456789,
        123456789
    };    

    return seqs;
}

int findLowIndex(int low, vector<long> &seq){
    int index = -1;
    for(int i = 0; i < seq.size() ;i++){
        if(seq[i] > low){
            index = i - 1;
            break;
        }
    }// end for i

    return index;
}

int findHighIndex(int high, vector<long> &seq) {
    int index = -1;
    for(int i = seq.size() - 1; i >= 0 ;i--){
        if(seq[i] < high) {
            index = i + 1;
            break;
        }
    }//end for i
    
    return index;
}

vector<int> sequentialDigits(int low, int high) {
    vector<int> result;
    vector<long> seq = buildSeq();
    
    int left = findLowIndex(low, seq);
    if(left < 0){
        left = 0;
    }

    int right = findHighIndex(high, seq);
    if(right >= seq.size()) {
        right = seq.size() - 1;
    }
    
    for(int i = left; i <= right ; i++){
        if(seq[i] >= low && seq[i] <= high){
            result.push_back(seq[i]);
        }
    }
    
    return result;        
}

int main() {
    auto result = sequentialDigits(10,1000000000);
    
    for(auto& v : result) {
        std::cout << v << " ,";
    }    
    std::cout << std::endl;
    return 0;
}




