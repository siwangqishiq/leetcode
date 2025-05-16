#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>

using namespace std;

char findTheDifference(string s, string t) {
    unordered_map<char,int> charRecords;
    for(size_t i = 0 ; i < t.length() ; i++){
        const char ch = t[i];
        if(charRecords.find(ch) == charRecords.end()){
            charRecords[ch] = 1;
        }else{
            charRecords[ch] = charRecords[ch] + 1;
        }
    }//end for i
    
    for(size_t i = 0 ; i < s.length() ; i++){
        const char chInS = s[i];
        int count = charRecords[chInS];
        charRecords[chInS] = count - 1;
    }//end for i

    for(auto p : charRecords){
        if(p.second == 1){
            return p.first;
        }
    }//end for each
    return '\0';
}

int main(){
    string s = "aa";
    string t = "aaa";
    auto result = findTheDifference(s , t);
    std::cout << "result :" << result << std::endl;
    return 0;
}



