#include <string>
#include <iostream>

using namespace std;

/**
 * 
 * 
 * 给定一个经过编码的字符串，返回它解码后的字符串。
编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
测试用例保证输出的长度不会超过 105。
 

示例 1：

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
 */

string decode(string &str, int &offset){
    std::string result = "";
    int numberValue = 0;
    string subStr = "";
    while(offset < str.size()){
        // std::cout << "offset = " << offset << std::endl;
        const char ch = str[offset];
        if(ch >= 'a' && ch <= 'z'){
            result += ch;
            offset++;
        }else if(ch >= '0' && ch <= '9'){
            numberValue = 10 * numberValue + (ch - '0');
            offset++;
        }else if(ch == '[') {
            offset++;
            subStr = decode(str, offset);
            string subResult = "";
            // std::cout << "subResult = " << subResult << " numberValue = " << numberValue << std::endl;
            for(int i = 0 ; i < numberValue ; i++){
                subResult = subResult + subStr;
            }//end for 
            result = result + subResult;
            numberValue = 0;
        }else if(ch == ']'){
            offset++;
            break;
        }
    }// end while
    return result;    
}

string decodeString(string s) {
    int index = 0;
    return decode(s, index);    
}


// 2[abc]3[cd]ef
int main() {
    // char c1 = 'a';
    // char c2 = 'b';
    // char c3 = 'c';
    // std::cout << c1 << " " << c2 << " " << c3 << std::endl;
    // std::cout << int(c1) << " " << int(c2) << " " << int(c3) << std::endl;

    // char c4 = '0';
    // char c5 = '1';
    // std::cout << c4 << "  " << c5 << std::endl;
    // std::cout << int(c4) << "  " << int(c5) << std::endl;


    // string str = "3[a2[c]]";
    // string str = "3[a]2[bc]";
    // string str = "2[abc]kkk";
    // string str = "3[a]2[b]";
    string str = "2[abc]3[cd]ef";
    std::cout << decodeString(str) << std::endl;
    return 0;
}
