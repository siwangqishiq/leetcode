#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s) {
    const char *str = s.c_str();
    int len = s.size();
    int index = len -1;
    int count = 0;

    int lastWordIndex = -1;
    //1.find
    while(index >= 0){
        if(str[index] != ' '){
            lastWordIndex = index;
            break;
        }
        index--;
    }//end while

    //2.count
    index = lastWordIndex;
    while(index >= 0){
        if(str[index] == ' '){
            break;
        }
        count++;
        index--;
    }//end while
    
    return count;
}

int main(){
    cout << lengthOfLastWord("   ") << endl;
    return 0;
}