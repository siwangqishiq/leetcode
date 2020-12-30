/**
*
数字 n 代表生成括号的对数，请你设计一个函数，
用于能够生成所有可能的并且 有效的 括号组合。

示例：
输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/generate-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/


#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

bool isValidate(string &str){
    if(str.empty())
        return true;
        
    stack<char> brackStack;
    const char *pStr = str.c_str();
    int index = 0;
    while(index < str.size()){
        char ch = pStr[index];

        if(ch == '('){
            brackStack.push(ch);
        }else if(ch == ')'){
            if(brackStack.size() > 0){
                brackStack.pop();
            }else{
                //cout << str << "  " << false << endl;
                return false;
            }
        }
        index++;
    }//end while

    //cout << str << "  " << true << endl;
    return true;
}

void buildSubTree(int deep ,string s ,int left , int right , vector<string> &result){
    if(!isValidate(s))
        return;

    if(left == 0 && right == 0){
        result.push_back(s);
        return;
    }

    //build left node
    if(left > 0){
        buildSubTree(deep + 1 ,s + "(",  left - 1  , right ,result);
    }

    //build right node
    if(right > 0){
        buildSubTree(deep + 1 , s+ ")" , left , right -1 ,result);
    }
}

vector<string> generateParenthesis(int n){
    vector<string> result;
    if(n <= 0)
        return result;

    buildSubTree(0 , "" , n , n , result);
    return result;
}

void printVec(vector<string> vec){
    for(auto &s : vec){
        cout << s << endl;
    }
}

int main() {
    printVec(generateParenthesis(4));
    return 0;
}




