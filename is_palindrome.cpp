
#include <iostream>
#include <string>
#include <map>

using namespace std;

bool judgePalindrome(string &str){
    const int len = str.length();
    const int mid = str.length() / 2;
    for(int i = 0 ; i < mid; i++){
        if(str[i] != str[len - i - 1]){
            return false;
        }
    }//end for i
    return true;
}

char convertUpperChar(char ch){
    return ch - ('A' - 'a');
}

bool isPalindrome(string s) {
    const std::string supportChars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map<char , int> suppMap;
    for(char ch : supportChars){
        suppMap[ch] = 1;
    }//end for each

    const std::string upperChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map<char , int> upperMap;
    for(char ch : upperChars){
        upperMap[ch] = 1;
    }//end for each

    string str = "";
    for(int i = 0 ; i < s.length() ; i++){
        char ch = s[i];
        if(suppMap.find(ch) != suppMap.end()){
            if(upperMap.find(ch) != upperMap.end()){
                str.append(std::string() + convertUpperChar(ch));
            }else{
                str.append(std::string() + ch);
            }
        }else{
            continue;
        }
    }//end for i

    // std::cout << "str :" << str << endl;
    return judgePalindrome(str);        
}

int main(){
    // string str = "A man, a plan, a canal: Panama";
    string str = " ";
    cout << isPalindrome(str) << endl;
    return 0;
}
