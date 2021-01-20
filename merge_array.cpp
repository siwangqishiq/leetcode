#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> tmp;

    int indexA = 0;
    int indexB = 0;
    while(indexA < m && indexB < n){
        if(nums1[indexA] < nums2[indexB]){
            tmp.push_back(nums1[indexA]);
            indexA++;
        }else{
            tmp.push_back(nums2[indexB]);
            indexB++;
        }
    }//end while

    while(indexA < m){
        tmp.push_back(nums1[indexA]);
        indexA++;
    }

    while(indexB < n){
        tmp.push_back(nums2[indexB]);
        indexB++;
    }

    nums1.erase(nums1.begin() , nums1.end());
    nums1.insert(nums1.end(),tmp.begin() , tmp.end());
}

int main(){
    return 0;
}