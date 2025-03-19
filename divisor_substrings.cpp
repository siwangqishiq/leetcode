
#include <iostream>
#include <string>

using namespace std;

int parseStrToInt(std::string &str){
    if(str.empty()){
        return 0;
    }

    int retValue = 0;
    const int len = str.length();
    int index = 0;
    while(index < len){
        retValue = 10 * retValue;

        char ch = str[index];
        int intValue = 0;
        switch(ch){
            case '1':
                intValue = 1;
                break;
            case '2':
                intValue = 2;
                break;
            case '3':
                intValue = 3;
                break;
            case '4':
                intValue = 4;
                break;
            case '5':
                intValue = 5;
                break;
            case '6':
                intValue = 6;
                break;
            case '7':
                intValue = 7;
                break;
            case '8':
                intValue = 8;
                break;
            case '9':
                intValue = 9;
                break;
            default:
                intValue = 0;
                break;
        }//end swtich
        retValue = retValue + intValue;

        index++;
    }//end while
    return retValue;
}

int divisorSubstrings(int num, int k) {
    string numStr = std::to_string(num);

    int result = 0;
    int i = 0;
    int j = i + k;
    while(i <= numStr.length() - k){
        auto subStr = numStr.substr(i, j);
        // cout << "subStr: " << subStr << endl;
        int strValue = parseStrToInt(subStr);

        if(strValue != 0 && (num % strValue == 0)){
            // cout << "strValue : " << strValue << " + 1" << endl;
            result++;
        }
        i++;
    }//end while

    return result;        
}

int main(){
    int num = 430043;
    int k = 2;
    auto result = divisorSubstrings(num , k);
    cout << "result : " << result << endl;

    // std::string str = "00801";
    // cout << parseStrToInt(str) << endl;
    
    return 0;
}


