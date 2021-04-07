/**
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array
 * 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MinHeap{
public:
    MinHeap(int size){
        this->size = size;
        this->data = new int[this->size];
    }

    int push(int value){

        return 0;
    }

    bool isFull(){
        return index >= size;
    }

    int getMinTop(){
        return data[0];
    }

    int removeTop(){
        return 0;
    }

    ~MinHeap(){
        delete[] data;
    }
private:
    int size;
    int *data;
    int index = 0;
};

int findKthLargest(vector<int> &nums, int k){
    vector<int> subVec;
    for(int i = 0 ;i < k ;i++){
        subVec.push_back(nums[i]);
    }//end for i
    
    sort(subVec.begin() , subVec.end());
    for(int i = k ;i < nums.size();i++){
        if(nums[i] > subVec[0]){
            subVec[0] = nums[i];
            sort(subVec.begin() , subVec.end());
        }
    }//end for i

    return subVec[0];        
}

int main(){
    vector<int> nums = {3,2,1,5,6,4};
    int r = findKthLargest(nums , 2);
    cout << r << endl;
    return 0;
}

