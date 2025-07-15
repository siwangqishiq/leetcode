#include <iostream>
#include <string>
#include <set>

using namespace std;

set<char> genLetterSets(string &letters){
    set<char> resultSets(letters.begin(), letters.end());
    // for(auto& ch : letters){
    //     resultSets.insert(ch);
    // }//end for each
    return resultSets;
}

bool isValid(string word) {
    if(word.length() < 3){
        return false;
    }

    string vowelLetters = "aeiouAEIOU";
    set<char> vowSet = genLetterSets(vowelLetters);

    string consonantLetters = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    set<char> consonantSet = genLetterSets(consonantLetters);

    string numberLeters = "9876543210";
    set<char> numberSet = genLetterSets(numberLeters);

    bool hasVow = false;
    bool hasCons = false;
    for(size_t i = 0 ; i < word.length(); i++){
        const char ch = word.at(i);
        if(vowSet.find(ch) != vowSet.end()){
            hasVow = true;
            continue;
        }

        if(consonantSet.find(ch) != consonantSet.end()){
            hasCons = true;
            continue;
        }

        if(numberSet.find(ch) == numberSet.end()){
            return false;
        }
    }//end for i
    
    return hasVow && hasCons;        
}

int main(){
    string word = "a3$e";
    auto result = isValid(word);
    cout << "result : " << result << endl;
    return 0;
}