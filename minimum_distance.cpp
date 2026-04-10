#include <iostream>
#include <vector>
#include <map>

using namespace std;

int findMinDis(vector<int> &idx){
    int minValue = INT_MAX;

    if(idx.size() < 3){
        return minValue;
    }

    for(int i = 0 ; i < idx.size() - 2 ; i++){
        int curValue = idx[i + 2] - idx[i + 1];
        curValue += idx[i + 2] - idx[i];
        curValue += idx[i + 1] - idx[i];

        if(curValue < minValue){
            minValue = curValue;
        }
    }//end for i
    return minValue;
}

int minimumDistance(vector<int>& nums) {
    map<int, vector<int>> numMap;
    for(int i = 0 ; i < nums.size() ; i++){
        int value = nums[i];
        if(numMap.find(value) == numMap.end()){//not found
            numMap[value] = vector<int>{i};
        }else{
            numMap[value].emplace_back(i);
        }
    }//end for i

    int minValue = INT_MAX;
    for(auto &p : numMap){
        if(p.second.size() >= 3){
            int dis = findMinDis(p.second);
            if(dis < minValue){
                minValue = dis;
            }
            // std::cout << p.first << " -> " << minValue << std::endl;
        }//end if
        // std::cout << p.first << " -> " << p.second.size() << std::endl;
    }//end for each

    return minValue == INT_MAX?-1:minValue;
}

void test_findMinDis(){
    vector<int> nums = {1,5,6,7,9};
    auto result = findMinDis(nums);
    std::cout << "result = " << result << std::endl;
}


int main(){
    // vector<int> nums = {1,1,2,3,2,1,2};
    vector<int> nums = {1,2,1,1,2,2};
    auto result = minimumDistance(nums);
    std::cout << "result = " << result << std::endl;
    return 0;
}


