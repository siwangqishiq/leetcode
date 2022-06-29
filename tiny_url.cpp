
#include <iostream>
#include <string>
#include <map>
#include <random>

using namespace std;

class Solution{
private:
    const string TINY_URL = "http://tinyurl.com/";
    map<string , string> tinyToUrlMap;

    void parseUrl(string &url , string &path){
        if(url.find(TINY_URL) != string::npos){
            path = url.substr(url.find(TINY_URL) + string(TINY_URL).size() , url.size());
        }
    }

    string genRandomStr(int weight = 8){
        string result;
        char tmp;

        default_random_engine engin;    //得到一个随机数生成器
        engin.seed(time(nullptr)); //传入种子
        uniform_int_distribution<int> dist(0, 35);  //得到一个随机分布
        for(int i = 0 ; i< weight; i++){
            tmp =  dist(engin);
            if(tmp <= 10){
                tmp += '0';
            }else{
                tmp -= 10;
                tmp += 'a';
            }//end if

            result += tmp;
        }//end for i

        return result;
    }

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl;
        do{
            shortUrl = genRandomStr();
        }while(tinyToUrlMap.find(shortUrl) != tinyToUrlMap.end());//end while
        tinyToUrlMap[shortUrl] = longUrl;
        return TINY_URL + shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string path;
        parseUrl(shortUrl , path);
        return tinyToUrlMap[path];
    }
};

int main(){
    Solution s = Solution();
    string shortUrl = s.encode("https://leetcode.com/problems/design-tinyurl");
    cout << "short url : " << shortUrl << endl;
    string longUrl = s.decode(shortUrl);
    cout << "origin url : " << longUrl << endl;

    return 0;
}



