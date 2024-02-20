
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Trie {
public:
    Trie() {
    }
    
    void insert(string word) {
        wordMap[word] = 1;
    }
    
    bool search(string word) {
        return wordMap.find(word) != wordMap.end();
    }
    
    bool startsWith(string prefix) {
        for(auto &p : wordMap){
            if(p.first.rfind(prefix, 0) == 0){
                return true;
            }
        }
        return false;
    }
private:
    unordered_map<string , int> wordMap;
};

int main(){
    Trie t;
    cout << t.search("apple") << endl;
    t.insert("apple");
    cout << t.search("apple") << endl;

    cout << t.startsWith("appl2") << endl;

    return 0;
}
