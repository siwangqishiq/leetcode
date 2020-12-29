
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void addLetter(char ch , map<char ,vector<char>> &t9 , vector<string> &result){
    vector<char> letters = t9[ch];
    if(letters.empty()){
        return;
    }

    vector<string> sub(result.begin() ,result.end());

    result.clear();
    for(string s : sub){
        for(int i = 0 ; i < letters.size();i++){
            result.push_back(s + letters[i]);
        }//end for i
    }//end for each
}

vector<string> letterCombinations(string digits){
    vector<string> result;

    if(digits.empty())
        return result;

    result.push_back("");

    map<char , vector<char>> t9;
    t9['2'] = {'a' , 'b' , 'c'};
    t9['3'] = {'d' , 'e' , 'f'};
    t9['4'] = {'g' , 'h' , 'i'};
    t9['5'] = {'j' , 'k' , 'l'};
    t9['6'] = {'m' , 'n' , 'o'};
    t9['7'] = {'p' , 'q' , 'r' , 's'};
    t9['8'] = {'t' , 'u' , 'v'};
    t9['9'] = {'w' , 'x' , 'y' ,'z'};

    const char *pStr = digits.c_str();
    int index = 0;
    while(index < digits.size()){
        addLetter(pStr[index] , t9 , result);
        index++;
    }//end while

    
    return result;
}

void printStringVec(vector<string> &strs){
    for(auto &s : strs){
        cout << s << " ";
    }
    cout << endl;
}

int main(){
    vector<string> r = letterCombinations("23");
    printStringVec(r);
    return 0;
}