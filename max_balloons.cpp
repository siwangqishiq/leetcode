#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool eatChar(unordered_map<char, int> &letters, char ch){
    // std::cout << "eat ch = " << ch << std::endl;

    if(letters.find(ch) == letters.end()){
        return false;
    }

    int chCount = letters[ch];
    if(chCount <= 0) {
        return false;
    }

    chCount = chCount - 1;
    letters[ch] = chCount;
    return true;
}


int maxNumberOfBalloons(string text) {
    unordered_map<char, int> letters;

    for(int i = 0 ; i < text.size() ; i++){
        const char ch = text[i];
        if(letters.find(ch) == letters.end()){
            letters[ch] = 1;
        }else{
            letters[ch] = letters[ch] + 1;
        }
    }//end for i

    // for(auto p : letters){
    //     std::cout << p.first << " -> " << p.second << std::endl;
    // }

    int counter = 0;
    int index = 0;
    const string WORD = "balloon";
    bool finFlag = false;
    while(true){
        const char ch = WORD[index];
        switch (index)
        {
        case 0://b
            if(!eatChar(letters, 'b')){
                finFlag = true;
            }
            break;
        case 1://a
            if(!eatChar(letters, 'a')){
                finFlag = true;
            }
            break;
        case 2://l
            if(!eatChar(letters, 'l')){
                finFlag = true;
            }
            break;
        case 3://l
            if(!eatChar(letters, 'l')){
                finFlag = true;
            }
            break;
        case 4://o
            if(!eatChar(letters, 'o')){
                finFlag = true;
            }
            break;
        case 5://o
            if(!eatChar(letters, 'o')){
                finFlag = true;
            }
            break;
        case 6://n
            if(eatChar(letters, 'n')){
                counter++;
            }else{
                finFlag = true;
            }
            break;
        }//end switch

        if(finFlag){
            break;
        }

        index = (index + 1) % WORD.size();
    }//end while

    return counter;
}

int main() {
    string text = "leetcode";
    auto result = maxNumberOfBalloons(text);
    std::cout << "max number of balloons : " << result << std::endl;
    return 0;
}