#include <iostream>
#include <vector>
#include <cstdint>
#include <map>

using namespace std;

// void genDp(vector<int> &nums, uint8_t *dp){
//     const int size = nums.size();
//     for(int i = 0 ; i < size ;i++){
//         dp[size * i + i] = 1;
//     }//end for i

//     int len = size - 1;
//     for(int len = 1 ; len < size ; len++){
//         int i = 0;
//         while(i + len < size){
//             const int j = i + len;
//             if(dp[size * i + j - 1] == 0){
//                 dp[size + i + j] = 0;
//             }else if(dp[size * i + j - 1] == 1){
//                 bool preOdd = (nums[j - 1] % 2 == 0);
//                 bool odd = (nums[j] % 2 == 0);
//                 dp[size * i + j] = (odd == !preOdd)?1:0;
//             }
//             i++;
//         }//end while
//     }//end for len
// }


// vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
//     vector<bool> result;
    
//     const unsigned int size = nums.size();
//     uint8_t *dp = new uint8_t[size * size];
//     genDp(nums , dp);

//     for(auto &p:queries){
//         result.push_back(dp[size* p[0] + p[1]] == 1);
//     }//end for each

//     delete[] dp;
//     dp = nullptr;

//     return result;
// }

static int cacheHit = 0;

bool queryDp(vector<int> &nums , int from , int to , 
    map<unsigned int , bool> &cache , 
    const unsigned int &size){
    
    unsigned int key = from * size + to;

    if(cache.find(key) != cache.end()){
        return cache[key];
    }

    bool preOdd = queryDp(nums , from , to - 1 , cache , size);
    if(!preOdd){
        cache[key] = false;
        return false;
    }

    // bool preEleOdd = (nums[to - 1] % 2 == 0);
    // bool curEleOdd = (nums[to] % 2 == 0);
    // bool result = (preEleOdd == !curEleOdd);

    bool result = ((nums[to - 1] ^ nums[to])&0x01 == 1);
    cache[key] = result;
    return result;
}

vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    vector<bool> result(queries.size() , false);
    
    map<unsigned int , bool> cache;
    const unsigned int size = nums.size();
    for(int i = 0 ; i < size ; i++){
        cache[i * size + i] = true;
    }//end for i

    for(int i = 0 ; i < queries.size() ;i++){
        auto &p = queries[i];
        result[i] = queryDp(nums, p[0], p[1] , cache , size);
    }//end for i

    return result;
}


int main(){
    vector<int> nums= {3,4,1,2,6};
    /**
     * @brief 
     * 3,4,1,2,6
     * 
     * 1 1 1 1 0
     * 0 1 1 1 0 
     * 0 0 1 1 0
     * 0 0 0 1 0
     * 0 0 0 0 1
     * 
     */
    vector<vector<int>> queries = {{0,4}};

    isArraySpecial(nums , queries);
    return 0;
}
