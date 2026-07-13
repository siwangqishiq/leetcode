/**
给你一个字符串 s ，它只包含三种字符 a, b 和 c 。

请你返回 a，b 和 c 都 至少 出现过一次的子字符串数目。

示例 1：

输入：s = "abcabc"
输出：10
解释：包含 a，b 和 c 各至少一次的子字符串为 "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" 和 "abc" (相同字符串算多次)。
示例 2：

输入：s = "aaacb"
输出：3
解释：包含 a，b 和 c 各至少一次的子字符串为 "aaacb", "aacb" 和 "acb" 。
示例 3：

输入：s = "abc"
输出：1
 

提示：

3 <= s.length <= 5 x 10^4
s 只包含字符 a，b 和 c 。
 */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Info{
    int aCnt;
    int bCnt;
    int cCnt;
    int subStringCnt;

    Info(){
        aCnt = 0;
        bCnt = 0;
        cCnt = 0;
        subStringCnt = 0;
    }
};

int numberOfSubstrings(string s) {
    if(s.empty()){
        return 0;
    }

    const int size = s.size();
    vector<vector<Info *>> dp(size + 1, vector<Info *>(size + 1, nullptr));
    for(int i = 0 ; i < size; i++){
        dp[i][i] = new Info();
        const char ch = s[i];

        if(ch == 'a'){
            dp[i][i]->aCnt = 1;
        }else if(ch == 'b'){
            dp[i][i]->bCnt = 1;
        }else if(ch == 'c'){
            dp[i][i]->cCnt = 1;
        }
    }//end for i

    int len = 2;
    while(len <= size) {
        for(int i = 0 ; i < size - len; i++){
            dp[i][i + len - 1] = new Info();
            
            std::cout << i << "," << (i + len - 1) << " <-- " << i << "," << (i + len - 2) << std::endl;
            auto info = dp[i][i + len - 2];
            const char ch = s[i + len - 1];

            Info* &curInfo = dp[i][i + len - 1];
            if(ch == 'a'){
                curInfo->aCnt = info->aCnt + 1;
            }else if(ch == 'b'){
                curInfo->bCnt = info->bCnt + 1;
            }else if(ch == 'c'){
                curInfo->cCnt = info->cCnt + 1;
            }

            if(curInfo->aCnt >= 1 && curInfo->bCnt >= 1 && curInfo->cCnt >= 1){
                curInfo->subStringCnt = info->subStringCnt + 1;
            }else{
                curInfo->subStringCnt = info->subStringCnt;
            }

            std::cout << i << "," << (i + len - 1) << " <-- " << i << "," << (i + len - 2) << "  end " << std::endl;
        }//end for i

        len++;
    }//end while

    return dp[0][size]->subStringCnt;
}

int main() {
    std::string str = "abcabc";
    
    int num = numberOfSubstrings(str);
    std::cout << "num = " << num << std::endl;
    return 0;
}