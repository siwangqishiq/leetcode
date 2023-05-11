
/**
 * @file query_string.cpp
 * 
 * 
 * 给定一个二进制字符串 s 和一个正整数 n，
 * 如果对于 [1, n] 范围内的每个整数，
 * 其二进制表示都是 s 的 子字符串 ，
 * 就返回 true，否则返回 false 。
 * 子字符串 是字符串中连续的字符序列。
 * 
 * @author panyi
 * @brief 
 * @version 0.1
 * @date 2023-05-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <string>
#include <bitset>

using namespace std;

bool isSubString(string &str , string &sub){
    return str.find(sub) != string::npos;
}

string intToBinString(int n){
    if(n <= 0 ){
        return "";
    }

    string originStr = bitset<32>(n).to_string();
    string result = originStr.substr(originStr.find("1"));
    return result;
}


bool queryString(string s, int n) {
    for(int i = 1 ; i <= n ;i++){
        string binaryStr = intToBinString(i);
        if(!isSubString(s , binaryStr)){
            return false;
        }
    }//end for i    
    return true;        
}

int main(){
    cout << queryString("0110" , 3) << endl;
    cout << queryString("0110" , 4) << endl;
    return 0;
}



