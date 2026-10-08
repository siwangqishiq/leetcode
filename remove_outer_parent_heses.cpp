#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string removeOuterParentheses(string s) {
    if(s.empty()){
        return "";
    }

    vector<char> stack;
    const int size = s.length();
    int index = 1;
    stack.push_back(s[0]);

    unordered_map<int, int> outterHeseSet;
    outterHeseSet[0] = 1;

    while(index < size) {
        const char ch = s[index];
        if(ch == '('){
            stack.push_back(ch);
        } else {
            const char lastCh = stack[stack.size() - 1];
            if(lastCh == '('){
                stack.pop_back();
                if(stack.empty()){
                    outterHeseSet[index] = 1;
                    if(index + 1 < size){
                        index++;
                        stack.push_back(s[index]);
                        outterHeseSet[index] = 1;
                    }else{
                        break;
                    }
                }
            }else{
                std::cout << "s content error" << std::endl;
                return "";
            }//end if
        }
        index++;
    }//end while

    // for(auto p : outterHeseSet){
    //     std::cout << p.first << "  ";
    // }
    // std::cout << std::endl;

    string result = "";
    for(int i = 0 ; i < size; i++){
        if(outterHeseSet.find(i) == outterHeseSet.end()){
            result += s[i];
        }
    }

    return result;
}

int main(){
    // string s = "(()())(())";
    // string s = "(()())(())(()(()))";
    string s = "()()";
    auto result = removeOuterParentheses(s);
    std::cout << "result :" << result << std::endl;
    return 0;
}


