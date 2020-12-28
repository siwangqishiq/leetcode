
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void addLetter(char ch , map<char ,vector<char>> &t9 , vector<string> &result){

}

vector<string> letterCombinations(string digits){
    vector<string> result;

    map<char , vector<char>> t9;
    t9['2'] = {'a' , 'b' , 'c'};
    t9['3'] = {'d' , 'e' , 'f'};
    t9['4'] = {'g' , 'h' , 'i'};
    t9['5'] = {'j' , 'k' , 'l'};
    t9['6'] = {'m' , 'n' , 'o'};
    t9['7'] = {'p' , 'q' , 'r' , 's'};
    t9['8'] = {'t' , 'u' , 'v'};
    t9['9'] = {'x' , 'x' , 'y' ,'z'};

    
    return result;
}

int main(){
    return 0;
}