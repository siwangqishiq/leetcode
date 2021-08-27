/**
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

 

提示：

num1 和num2 的长度都小于 5100
num1 和num2 都只包含数字 0-9
num1 和num2 都不包含任何前导零
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 * */


#include <iostream>
#include <string>

using namespace std;

int charToInt(char ch){
    return ch  - '0';
}

char intToChar(int val){
    return val + '0';
}

int getWeightValue(string &str , int pos){
    if(pos < 0 || pos >= str.size())
        return 0;
    
    return charToInt(str[pos]);
}

string addStrings(string num1, string num2) {
    string result = "";
    if(num1.empty() || num2.empty())
        return "";
    
    string left;
    string right;
    //ensure left.size <= right.size
    if(num1.size() <= num2.size()){
        left = num1;
        right = num2;
    }else{
        left = num2;
        right = num1;
    }

    int index = 0;
    int priorValue = 0;
    for(;index < right.size();index++){
        int leftValue = getWeightValue(left , left.size() - index - 1);
        int rightValue = getWeightValue(right , right.size() - index - 1);

        //cout << leftValue << " + " << rightValue << endl;
        int addValue = leftValue + rightValue + priorValue;
        priorValue = 0;

        if(addValue >= 10){
            priorValue = 1;
            addValue = addValue - 10;
        }

        result = intToChar(addValue) + result;
    }//end for index

    if(priorValue > 0){
        result = intToChar(priorValue) + result;
    }
    
    return result;
}

int main(){
    cout << addStrings("1" , "99") << endl;
    return 0;
}


