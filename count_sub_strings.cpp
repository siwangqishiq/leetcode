#include <iostream>
#include <string>

using namespace std;

bool isLoopStr(string& str, int start, int end) {
    if(end <= start) {
        return false;
    }
    

    if(end - start == 1) {
        return true;
    }else{
        const int mid = (start + end ) >> 1;
        for(int i = start; i < mid ;i++) {
            if(str[i] != str[start + end - i - 1]) {
                return false;
            }
        }//end for i

        return true;
    }//end if
}


int countLoopSubString(string &str, int start , int end) {
    if(end <= start) {
        return 0;
    }else if(end - start == 1) {
        return 1;
    }    

    bool isLoop = isLoopStr(str, start, end);
    cout << "end is loopstr  " << start << "  " << end << std::endl;    

    const int mid = (start + end) >> 1;
    int leftCount = countLoopSubString(str, start, mid);
    int rightCount = countLoopSubString(str, mid, end);

    return leftCount + rightCount + (isLoop?1:0);
}

int countSubstrings(string s) {
    if(s.empty()) {
        return 0;
    }

    const int len = s.length();
    return countLoopSubString(s, 0, len);        
}


int main(){
    string s = "abc";

    auto result = countSubstrings(s);

    std::cout << "result = " << result << std::endl; 
    return 0;
}
