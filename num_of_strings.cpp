#include <iostream>
#include <vector>
#include <string>

using namespace std;

int findIndex(string &str, string &pattern){
    int offset = 0;
    for(int i = 0 ; i < str.size() ; i++) {
        offset = 0;
        while(offset < pattern.size()){
            if(str[i + offset] != pattern[offset]){
                break;
            }
            offset++;
        }//end while
        
        if(offset >= pattern.size()){
            return i;
        }
    }//end for i

    return -1;
}

int numOfStrings(vector<string>& patterns, string word) {
    int retCount = 0;
    for(auto &pattern : patterns) {
        if(findIndex(word, pattern) >= 0){
            retCount++;
        }
    }//end for each
    return retCount;        
}

int main() {
    // string str = "123";
    // string pattern = "12345";
    // auto index = findIndex(str, pattern);
    // std::cout << "index = " << index << std::endl;

    vector<string> patterns = {"a","a","a"};
    string word = "ab";
    auto count = numOfStrings(patterns, word);
    std::cout << "count = " << count << std::endl;
    return 0;
}
