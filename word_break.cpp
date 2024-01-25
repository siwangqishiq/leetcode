/**
 * @file word_break.cpp
 * 
 * 
 * https://leetcode.cn/problems/word-break
 * 
 * @brief 
 * @version 0.1
 * @date 2024-01-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool findWord(vector<string> &wordDict , string &word){
    for(int i = 0 ; i < wordDict.size() ;i++){
        if(wordDict[i]== word){
            return true;
        }
    }//end for i

    return false;
}

bool wordBreak(string str, vector<string>& wordDict) {
    if(str.empty()){
        return true;
    }

    sort(wordDict.begin() , wordDict.end() , [](string &w1 , string &w2){
        return w1.size() >= w2.size();
    });
    

    string subStr = "";
    int index = 0;
    while(index < str.size()){
        subStr += str[index];
        cout << "subStr : " << subStr << endl;
        if(findWord(wordDict , subStr)){ // hit word!
            cout << "subStr Hit!: " << subStr << endl;
            subStr = "";
        }
        index++;
    }//end while

    return subStr.empty();
}

int main(){
    string s = "aaaaaaa";
    vector<string> dict = {"aaaa", "aaa"};
    cout << "->" << wordBreak(s , dict) << endl;
    return 0;
}
