#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

vector<pair<int, int>> excludeZone(vector<pair<int, int>> subArray){
    if(subArray.empty()){
        return subArray;
    }

    vector<pair<int, int>> result;
    int last = subArray[0].second;
    result.push_back(subArray[0]);

    for(int i = 1 ; i < subArray.size() ; i++){
        if(last >= subArray[i].first){
            continue;
        }
        
        result.push_back(subArray[i]);
        last = subArray[i].second;
    }//end for i

    return result;
}

vector<pair<int, int>> searchSubArray(vector<int> &arr, int target) {
    vector<pair<int, int>> subArray;
    
    if(arr.empty()){
        return subArray;
    }
    
    int left = 0;
    int right = 0;
    int subSum = arr[0];
    
    while(left < arr.size() && right < arr.size()){
        // std::cout << "[ " << left << "  " << right <<" ]"<< std::endl;
        if(subSum < target){
            right++;
            if(right >= arr.size()){
                break;
            }
            subSum += arr[right];
        }else if(subSum > target){
            subSum -= arr[left];
            left++;
        }else{
            std::pair<int, int> p(left, right);
            subArray.push_back(p);
            right++;
            if(right >= arr.size()){
                break;
            }
            subSum += arr[right];
        }//end if
    }//end while

    return subArray;
}


int minSumOfLengths(vector<int>& arr, int target) {
    vector<pair<int, int>> subArray = searchSubArray(arr, target);

    for(auto &p : subArray){
        std::cout << p.first << "  " << p.second << std::endl;
    }//end for each
    
    std::sort(subArray.begin(), subArray.end(), [](pair<int,int> &left, pair<int,int> &right){
        return (right.second - right.first) - (left.second - left.first) > 0;
    });

    std::cout << "after sort\n";
    for(auto &p : subArray){
        std::cout << p.first << "  " << p.second << std::endl;
    }//end for each

    if(subArray.size() < 2){
        return -1;
    }

    vector<int> best(arr.size(), INT_MAX);

    int ans = INT_MAX;

    for (auto &p : subArray) {
        int left = p.first;
        int right = p.second;

        // 找当前子数组左边的最短子数组
        if (left > 0 && best[left - 1] != INT_MAX) {
            int currentLength = right - left + 1;
            ans = min(ans, currentLength + best[left - 1]);
        }

        // 更新 best[right]
        int currentLength = right - left + 1;

        if (right == 0) {
            best[right] = currentLength;
        } else {
            best[right] = min(best[right - 1], currentLength);
        }
    }

    return ans == INT_MAX ? -1 : ans;
}

int main(){
    // vector<int> arr = {3,1,1,1,5,1,2,1};
    // int target = 3;
    
    // vector<int> arr = {2,1,3,3,2,3,1};
    // int target = 6;

    vector<int> arr = {2,2,4,4,4,4,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int target = 20;

    auto result = minSumOfLengths(arr, target);
    
    std::cout << "result = " << result << std::endl;

    return 0;
}
