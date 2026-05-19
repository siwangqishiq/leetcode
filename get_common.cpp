#include <iostream>
#include <vector>

using namespace std;

int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int left = 0;
        int right = 0;

        while(left < nums1.size() && right < nums2.size()){
                if(nums1[left] > nums2[right]){
                        right++;
                }else if(nums1[left] < nums2[right]){
                        left++;
                }else {
                        return nums1[left];
                }
        }//end while

        return -1;
}


int main(){
        vector<int> nums1 = {1,2,3,6};
        vector<int> nums2 = {2,3,4,5};

        auto result = getCommon(nums1, nums2);
        std::cout << "result  = " << result << std::endl;
        return 0;
}
