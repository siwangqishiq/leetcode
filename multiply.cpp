/**
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/multiply-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

char mapIntToChar(int intValue){
    int delta = '0' - 0;
    return intValue + delta;
}

int mapCharToInt(char ch){
    return ch - '0';
}

int getWeightValue(string &str , int pos){
    if(pos >= str.size() || pos < 0)
        return 0;
    
    return mapCharToInt(str[pos]);
}

string strAdd(string num1 , string num2){
    string result = "";
    string left = num1;
    string right = num2;
    if(num1.size() >= num2.size()){//先比较字符串长度 始终保持left - size <= right-size
        left = num2;
        right = num1;
    }

    int index = 0;
    int prior = 0;//进位

    for(; index < right.size();index++){
        int v1 = getWeightValue(left , left.size() - index - 1);
        int v2 = getWeightValue(right , right.size() - index - 1);
        
        //cout << v1 << " + " << v2 << endl;
        int addResult = v1 + v2 + prior;
        prior = 0;
        if(addResult >= 10){
            addResult -= 10;
            prior = 1;
        }

        // char chValue = mapIntToChar(addResult);
        // cout << chValue << endl;
        // if(chValue != '0'){
        //     result = mapIntToChar(addResult) + result;
        // }

        result = mapIntToChar(addResult) + result;
    }//end for i

    if(prior != 0){
        result = mapIntToChar(prior) + result;
    }
    
    return result;
}

string multiplyChar(string num , char ch){
    int count = mapCharToInt(ch);
    string result = "0";
    
    for(int i = 0 ; i < count ;i++){
        result = strAdd(result , num);
        //cout << "result = " << result << endl;
    }//end for i
    return result;
}

string multiply(string num1, string num2) {
    if(num1 == "0" || num2 == "0")
        return "0";

    string result = "0";
    string numValue = num1;
    for(int i = 0; i < num2.size() ;i++){
        char num2WeightValue = num2[num2.size() - i - 1];
        string stepResult = multiplyChar(numValue , num2WeightValue);
        result = strAdd(result , stepResult);

        numValue = numValue + "0";
    }
    return result;
}

int main(){
    cout << multiply("10001", "10001") << endl;
    return 0;
}
