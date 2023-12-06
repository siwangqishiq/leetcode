#include <iostream>
#include <string>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    const int LEN = s.length();
    if(LEN <= 1){
        return LEN;
    }

    int leftIndex = 0;
    int rightIndex = 1;
    
    map<char , int> charMap;
    charMap[s[0]] = 1;

    int longestSubStringLen = 1;

    while(rightIndex < LEN){
        char ch = s[rightIndex];
        if(charMap.find(ch) == charMap.end()){//无重复
            charMap[ch] = 1;
            if(longestSubStringLen < charMap.size()){
                longestSubStringLen = charMap.size();
            }
        }else{ //发现重复
            while(leftIndex < rightIndex){
                char leftChar = s[leftIndex];
                if(leftChar != ch){
                    charMap.erase(leftChar);
                    leftIndex++;
                }else{
                    leftIndex++;
                    break;
                }
            }//end while
        }
        rightIndex++;
    }//end while

    return longestSubStringLen;
}

int main(){
    string str = "pwwkew";

    cout << "longest substring = " << lengthOfLongestSubstring(str) << endl;
    return 0;
}


