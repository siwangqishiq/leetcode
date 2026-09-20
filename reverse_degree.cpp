#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, int> buildReverseMap(){
    unordered_map<char, int> reverseMap;
    string chars = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i < chars.length() ; i++){
        reverseMap[chars[i]] = 26 - i;
    }//end for i
    return reverseMap;
}

int reverseDegree(string s) {
    int degree = 0;
    auto reverseMap = buildReverseMap();
    
    for(int i = 0 ; i < s.length() ; i++){
        degree += (i + 1) * reverseMap[s[i]];
    }//end for i
    return degree;
}

int main() {

    std::string s = "abc";
    int result = reverseDegree(s);

    std::cout << "reverse degree : " << result << std::endl; 

    return 0;
}
