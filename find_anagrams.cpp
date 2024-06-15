#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


void addCharCurrentMap(unordered_map<char , int> &curMap , char addChar){
    if(curMap.find(addChar) == curMap.end()){
        curMap[addChar] = 1;
    }else{
        int originCount = curMap[addChar];
        curMap[addChar] = originCount + 1;
    }
}

void removeCharCurrentMap(unordered_map<char , int> &curMap , char removeChar){
    if(curMap.find(removeChar) == curMap.end()){
        return;
    }else{
        int originCount = curMap[removeChar];
        if(originCount - 1 <= 0){
            curMap.erase(removeChar);
        }else{
            curMap[removeChar] = originCount - 1;
        }
    }
}

void buildLettersData(std::string &p , unordered_map<char , int> &lettersMap){
    lettersMap.clear();
    for(char ch : p){
        addCharCurrentMap(lettersMap , ch);
    }//end for each
}


bool compareMap(unordered_map<char , int> &lettersMap , unordered_map<char , int> &currentMap){
    if(lettersMap.size() != currentMap.size()){
        return false;
    }
    
    for(auto p : lettersMap){
        char ch = p.first;
        if(currentMap.find(ch) == currentMap.end()){
            return false;
        }else{
            int curCount = currentMap[ch];
            if(curCount != p.second){
                return false;
            }
        }//end if
    }//end for each
    return true;
}



vector<int> findAnagrams(string s, string p) {
    vector<int> result;

    if(p.length() > s.length()){
        return result;
    }

    unordered_map<char , int> lettersCountMap;
    unordered_map<char , int> curMap;

    buildLettersData(p , lettersCountMap);
    int const size = p.length();
    for(int i = 0 ; i < size ;i++){
        addCharCurrentMap(curMap , s[i]);
    }//end for i

    if(compareMap(lettersCountMap , curMap)){
        result.push_back(0);
    }

    for(int i = size ; i < s.length() ; i++){
        int end = i;
        int start = end - size;
        
        char addChar = s[end];
        addCharCurrentMap(curMap , addChar);

        char removeChar = s[start];
        removeCharCurrentMap(curMap , removeChar);

        if(compareMap(lettersCountMap , curMap)){
            result.push_back(start + 1);
        }//end if
    }//end for i

    return result;
}


void printVec(vector<int> &result){
    for(auto &r : result){
        cout << r << "  ";
    }
    cout << endl;
}

void tesBuildLettersData(unordered_map<char , int> &lettersMap){
    for(auto p : lettersMap){
        cout << p.first << " ==> " << p.second << endl;
    }

    lettersMap.erase('l');

    cout << "===========================" << endl;
    for(auto p : lettersMap){
        cout << p.first << " ==> " << p.second << endl;
    }
}

int main(){
    string s = "cbaebabacd";
    string p = "abc";
    auto result = findAnagrams(s , p);
    printVec(result);
    return 0;
}



