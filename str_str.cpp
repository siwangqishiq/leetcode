
#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle) {
    const char *pattern = needle.c_str();
    int patternLength = needle.size();
    if(patternLength == 0)
        return 0;

    const char *str = haystack.c_str();
    int strLength = haystack.size();

    int index = 0;
    for(int i = 0 ; i < strLength;i++){
        if(str[i] == pattern[index]){
            while(index < patternLength){
                //cout << str[i + index] << "  " << pattern[index] << endl;
                if(str[i + index] != pattern[index]){
                    break;
                }

                index++;
            }//end while

            if(index == patternLength){
                return i;
            }
        }
        index = 0;
    }

    return -1;
}

int main(){
    cout << strStr("aaaaa","bba") << endl;
    return 0;
}