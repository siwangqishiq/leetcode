#include <iostream>
#include <string>

using namespace std;

bool isBeautiful(string &sub, int k) {
    int count = 0;
    for(auto &c : sub){
        if(c == '1'){
            count++;
        }
    }//end for each
    return count == k;
}

int compareString(string &left, string &right){
    for(int i = 0 ; i < left.length() ; i++){
        if(left[i] - right[i] > 0){
            return 1;   
        }else if(left[i] - right[i] < 0){
            return -1;
        }
    }
    return 0;
}

std::string shortestBeautifulSubstring(string s, int k){
    if(s.empty()){
        return "";
    }

    const int size = s.length();
    int count = 0;
    string result = "";
    int shorestLength = size;
    
    for(int i = 0; i < size ;i++){
        for(int j = i + 1; j < size + 1; j++){
            string subString(s.begin() + i, s.begin() + j);
            // std::cout << "sub:" << subString << std::endl;
            if(isBeautiful(subString, k) && shorestLength >= subString.length()){
                shorestLength = j - i;
                if(subString.length() != result.length()){
                    result = subString;
                }else if(compareString(subString, result) < 0){
                    result = subString;
                }
            }
        }//end for j
    }//end for i
    return result;
}


int main(){
    string s = "001110101101101111";
    int k = 10;

    auto result = shortestBeautifulSubstring(s, k);
    std::cout << "result :" << result << std::endl; 
    return 0;
}
