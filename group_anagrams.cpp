/**
 * 49. 字母异位词分组
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct WordsInfo{
    int alpha[26];
};

void wordAddLetter(WordsInfo &info , char ch){
    int index = ch - 'a';
    info.alpha[index] += 1;
}

bool compareWordInfoIsSame(WordsInfo &leftInfo , WordsInfo &rightInfo){
    for(int i = 0 ; i < 26 ;i++){
        if(leftInfo.alpha[i] != rightInfo.alpha[i]){
            return false;
        }
    }//end for each

    return true;
}

unsigned int hashWordInfo(WordsInfo &info){
    unsigned int hash = 0;
    for(int i= 0 ; i < 26;i++){
        hash += info.alpha[i];
        hash *= 31;
    }

    return hash;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // map<char , unsigned int> alphaMask = buildAlphaMask();
    map<unsigned int , vector<string>> groups;
    for(string &s : strs){
        WordsInfo info={0};
        const char *pStr = s.c_str();
        for(int i = 0 ; i < s.size();i++){
            wordAddLetter(info , pStr[i]);
        }//end for i

        cout << s << "= " << hashWordInfo(info) << endl;

        unsigned int key = hashWordInfo(info);
        if(groups.find(key) == groups.end()){//not found
            vector<string> strs;
            strs.push_back(s);
            groups[key] = strs;
        }else{
             vector<string> strs = groups[key];

             strs.push_back(s);
             groups[key] = strs;
        }
    }//end for each

    vector<vector<string>> result;
    for(auto p : groups){
        result.push_back(p.second);
    }//end for each

    return result;
}




int main(){
    vector<string> strs = {"ddddddddddg","dgggggggggg"};
    // vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> result = groupAnagrams(strs);
    cout << " [ ";
    for(vector<string> strVec : result){
        cout << " [ ";
        for(string s : strVec){
            cout << s << " , ";
        }
        cout << " ]," << endl;
    }

    cout << " ] " << endl;
    
    return 0;
}
