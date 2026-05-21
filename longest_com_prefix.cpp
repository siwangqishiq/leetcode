#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int min(int a, int b){
    return a <= b? a : b;
}

int longestPrefix(string &str1, string &str2){
    int prefixLen = 0;
    int len = min(str1.length(), str2.length());
    for(int i = 0 ; i < len ; i++) {
        if(str1[i] != str2[i]){
            break;
        }

        prefixLen++;
    }//end for i
    return prefixLen;
}

struct TiesNode{
    bool isEnd;
    char value;
    map<char, TiesNode *> nexts;
};

void tiesEatChar(TiesNode *node, string &str, int index){
    if(node == nullptr || str.empty() || index >= str.length()) {
        return;
    }

    const char ch = str[index];
    // std::cout << "eat ch " << ch << std::endl;

    if(node->nexts.find(ch) == node->nexts.end()) { //not find the char
        TiesNode *nextNode = new TiesNode;
        nextNode->value = ch;
        nextNode->isEnd = false;

        node->nexts[ch] = nextNode;
    }

    TiesNode *nextNode = node->nexts[ch];
    if(index + 1 == str.length()){
        nextNode->isEnd = true;
    }else{
        tiesEatChar(nextNode, str, index + 1);
    }
}

void freeTiesNode(TiesNode *node){
    if(node == nullptr){
        return;
    }

    // next node free
    for(auto &p : node->nexts){
        freeTiesNode(p.second);
    }//end for each

    // self free
    delete node;
}

TiesNode* buildTies(vector<int> &arr) {
    TiesNode *root = new TiesNode;
    root->isEnd = false;
    
    for(auto &item : arr){
        string str = std::to_string(item);
        tiesEatChar(root, str, 0);
    }//end for each;
    return root; 
}

int searchPrefixGetLength(TiesNode *root, string &str){
    if(root == nullptr){
        return 0;
    }

    int len = 0;
    int index = 0;
    TiesNode *node = root;
    while(node != nullptr && index < str.length()){
        const char ch = str[index];
        if(node->nexts.find(ch) == node->nexts.end()) {
            break;
        }

        node = node->nexts[ch];

        len++;
        index++;
    }//end while 

    return len;
}

int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    if(arr1.empty() || arr2.empty()){
        return 0;
    }

    int longestLen = 0;
    TiesNode *root = buildTies(arr1);

    for(int &item : arr2){
        string str = std::to_string(item);
        int len = searchPrefixGetLength(root, str);
        if(len > longestLen){
            longestLen = len;
        }
    }

    freeTiesNode(root);
    return longestLen;       
}


int main(){
    // vector<int> arr1 = {1,10,100};      
    // vector<int> arr2 = {1000};

    vector<int> arr1 = {1,2,3};      
    vector<int> arr2 = {4,4,4};

    auto result = longestCommonPrefix(arr1, arr2);

    std::cout << "result = " << result << std::endl;
    return 0;
}
