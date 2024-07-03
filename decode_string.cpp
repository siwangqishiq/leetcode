/**
 * @file decode_string.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-17
 * 
 * https://leetcode.cn/problems/decode-string/description/?envType=problem-list-v2&envId=2cktkvj
 * 
 * @copyright Copyright (c) 2024
 * 
 * 
 * 示例 1：

输入：s = "3[a]2[bc]"
输出："aaabcbc"
示例 2：

输入：s = "3[a2[c]]"
输出："accaccacc"
示例 3：

输入：s = "2[abc]3[cd]ef"
输出："abcabccdcdcdef"
示例 4：

输入：s = "abc3[cd]xyz"
输出："abccdcdcdxyz"
 * 
 */

#include <iostream>
#include <string>

using namespace std;

enum State{
    IDLE,
    READ_NUM,
    READ_STR
};

string parseString(string &s , int offset){
    State state = IDLE;

    int index = offset;
    string numStr = "";
    string contentStr = "";
    int count = 0;

    while(index < s.length()){
        char ch = s[index];
        switch(ch){
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                if(state == IDLE || state == READ_STR){
                    state = READ_NUM;
                }
                numStr = numStr + std::to_string(ch);
                index++;
                break;
            case '[':
                if(state == READ_NUM){
                    count = std::atoi(numStr.c_str());
                }
                index++;
                break;
            case ']':
                index++;
                break;
            default:
                if(state == IDLE){
                    state = READ_STR;
                }
                contentStr = contentStr + std::to_string(ch);
                index++;
                break;
        }//end switch
    }//end while
    return ""; 
}

string decodeString(string s) {

    return "";
}

int main(){
    return 0;
}
