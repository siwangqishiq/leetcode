
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<char> originChar = {'a','e','i','o','u'};

int getConsonantCount(map<char, int> &charCountMap){
    int totalCount = 0;
    for(auto &p : charCountMap){
        totalCount += p.second;
    }//end for each

    int originCharCount = 0;
    for(char &ch : originChar){
        originCharCount += charCountMap[ch];
    }//end for each
    return totalCount - originCharCount;
}

bool checkEnoughOriginChar(map<char, int> &charCountMap){
    for(char &ch : originChar){
        int chCount = charCountMap[ch];
        if(chCount <= 0){
            return false;
        }
    }//end for each
    return true;
}

void updateCharCountMap(map<char, int> &charCountMap , char ch , bool isAdd){
    int count = charCountMap[ch];
    if(isAdd){
        charCountMap[ch] = count + 1;
    }else{
        charCountMap[ch] = (count >= 1)?(count - 1):0;
    }//end if
}

int countOfSubstrings(string word, int k) {
    int left = 0;
    int right = 0;
    int count = 0;

    map<char, int> charCountMap;

    while(right < word.length()){
        // string str = word.substr(left, right - left + 1);
        // cout << "str = " << str << endl;

        if(!checkEnoughOriginChar(charCountMap)){
            char ch = word[right];
            updateCharCountMap(charCountMap, ch , true);

            right++;
            continue;
        }

        int conCount = getConsonantCount(charCountMap);
        if(conCount > k){
            char ch = word[left];
            updateCharCountMap(charCountMap, ch , false);

            left++;
        }else if(conCount < k){
            char ch = word[right];
            updateCharCountMap(charCountMap, ch , true);
            right++;
        }else{
            count++;
            
            char ch = word[right];
            updateCharCountMap(charCountMap, ch , true);
            right++;
        }
    }//end while

    while(left < word.length()){
        // cout << "left : " << left << endl;
        if(!checkEnoughOriginChar(charCountMap)){
            break;
        }

        int conCount = getConsonantCount(charCountMap);
        if(conCount > k){
            char ch = word[left];
            updateCharCountMap(charCountMap, ch , false);
            left++;
        }else if(conCount == k){
            count++;

            char ch = word[left];
            updateCharCountMap(charCountMap, ch , false);
            left++;
        }else{
            break;
        }
    }//end while;

    return count;        
}

int main(){
    string word = "ieaouqqieaouqq";
    int k = 1;

    // string word = "aeiou";
    // int k = 0;

    // string word = "aeioqq";
    // int k = 1;

    // string word = "iqeaouqi";
    // int k  =2;

    string word = "ieiaoud";
    int k = 0;

    auto result = countOfSubstrings(word , k);
    cout << "result : " << result << endl;
    return 0;
}

