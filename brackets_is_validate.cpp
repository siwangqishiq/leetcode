/**
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，
 * 判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 * */


#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool popStack(stack<char> &bracketStack , char ch){
    if(bracketStack.empty()){
        return false;
    }

    char topElem = bracketStack.top();
    bracketStack.pop();

    if(ch == ')'){
        return topElem == '(';
    }else if(ch == ']'){
        return topElem == '[';
    }else if(ch == '}'){
        return topElem == '{';
    }

    return false;
}

bool isValid(string s) {
    if(s.empty())
        return true;

    stack<char> bracketStack;
    const char *pStr = s.c_str();
    
    while(*pStr != '\0'){
        const char ch = *pStr;
        
        switch(ch){
            case '(':
            case '[':
            case '{':
                bracketStack.push(ch);
                break;
            case ')':
            case ']':
            case '}':
                if(!popStack(bracketStack , ch)){
                    return false;
                }
                break;
            default:
                break;
        }//end switch
        pStr++;
    }//end while
    return bracketStack.empty();
}

int main(){
    cout << isValid("()[]{}") << endl;
    cout << isValid("()") << endl;

    cout << isValid("(]") << endl;

    cout << isValid("([)]") << endl;

    cout << isValid("{[]}") << endl;
    return 0;
}