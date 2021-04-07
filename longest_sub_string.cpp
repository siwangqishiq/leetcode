/**
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
示例 4:

输入: s = ""
输出: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 * */

#include <iostream>
#include <map>
#include <string>

using namespace std;


int lengthOfLongestSubstring(string s) {
    if(s.empty())
        return 0;
    int left;
    int right;
    int len = s.size();

    const char *p = s.c_str();
    left = right = 0;
    int maxLength = -1;
    map<char , int> memo;

    while(right < len){
        char ch = p[right];
        if(memo.find(ch) == memo.end()){//not found
            memo[ch] = 1;
        }else{//found
            //move left
            while(left <= right){
                char leftChar = p[left];                
                memo.erase(leftChar);
                
                left++;
                if(leftChar == ch){
                    memo[ch] = 1;
                    break;
                }
                
            }//end while
        }

        // cout << "left = " << left << "  right = " << right <<  endl;

        // cout << "map : { ";
        // for(auto &p : memo){
        //     cout << p.first << " ";
        // }
        // cout << " }" << endl;

        int subLen = right- left + 1;
        // string subStr = s.substr(left , subLen);
        // cout << "subStr = " << subStr << endl;
        // cout << endl;
       
        if(subLen > maxLength){
            maxLength = subLen;
        }
        right++;
    }//end while

    return maxLength;
}


int main(){
    int result = lengthOfLongestSubstring("abcabcbb");
    cout << result << endl;
    return 0;
}