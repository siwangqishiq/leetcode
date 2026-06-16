#include <string>
#include <iostream>

using namespace std;

/**
 * 字符 '*' 会 删除 result 中的最后一个字符（如果存在）。
字符 '#' 会 复制 当前的 result 并 追加 到其自身后面。
字符 '%' 会 反转 当前的 result。
 */
void reverseBuff(char *buf, int bufLen){
    if(buf == nullptr || bufLen <= 0){
        return;
    }

    const int mid = bufLen >> 1;
    for(int i = 0 ; i < mid; i++){
        auto tmp = buf[i];
        buf[i] = buf[bufLen - i - 1];
        buf[bufLen - i - 1] = tmp;
    }//end for i
}

void deleteChar(char *buf, int &bufLen){
    if(buf == nullptr || bufLen <= 0){
        return;
    }
    bufLen--;
}

void copyChar(char *buf, int &bufLen){
    if(buf == nullptr || bufLen <= 0){
        return;
    }

    for(int i= 0 ; i < bufLen; i++){
        buf[bufLen + i] = buf[i];
    }//end for i
    bufLen += bufLen;
}
 
string processStr(string s) {
    char buf[1024 * 1024];
    int bufLen = 0;
    int index = 0;

    while(index < s.size()) {
        const char ch = s[index];
        switch(ch){
            case '*':
                deleteChar(buf, bufLen);
                break;
            case '%':
                reverseBuff(buf, bufLen);
                break;
            case '#':
                copyChar(buf, bufLen);
                break;
            default:
                buf[bufLen] = ch;
                bufLen++;
                break;
        }//end switch
        index++;
    }//end while
    return std::string(buf, 0 , bufLen);
}

int main() {
    // string str = "a#b%*";
    string str = "z*#";
    auto result = processStr(str);
    std::cout << "result :" << result << std::endl;
    return 0;
}