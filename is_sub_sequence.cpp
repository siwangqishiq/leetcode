#include <iostream>
#include <string>

using namespace std;

int findIndex(string &content , char ch , int offset){
    for(int i = offset; i < content.length() ;i++){
        if(ch == content[i]){
            return i;
        }
    }//end for i
    return -1;
}

bool isSubsequence(string sub, string content) {
    int offset = 0;
    for(char ch : sub){
        int findPos = findIndex(content , ch , offset);
        if(findPos < 0){ //not found
            return false;
        }else{
            offset = findPos + 1;
        }//end if
    }//end for each
    return true;
}

int main(){
    string s = "abg";
    string t = "ahbgdc";
    cout << isSubsequence(s , t) << endl;
    return 0;
}