/**
 * 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

 

示例 1：

输入：nums = [2,0,2,1,1,0]
输出：[0,0,1,1,2,2]
示例 2：

输入：nums = [2,0,1]
输出：[0,1,2]
示例 3：

输入：nums = [0]
输出：[0]
示例 4：

输入：nums = [1]
输出：[1]
 

提示：

n == nums.length
1 <= n <= 300
nums[i] 为 0、1 或 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-colors
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */

#include <iostream>
#include <vector>
#include <map>


using namespace std;

void sortColors(vector<int> &nums){
    const int RED_VALUE = 0;
    const int WHITE_VALUE = 1;
    const int BLUE_VALUE = 2;

    int redCount = 0;
    int whiteCount = 0;
    int blueCount = 0;

    for(int i = 0 ; i < nums.size() ; i++){
        int val = nums[i];
        switch(val){
            case RED_VALUE:
                redCount++;
                break;
            case WHITE_VALUE:
                whiteCount++;
                break;
            case BLUE_VALUE:
                blueCount++;
                break;
            default:
                break;
        }//end for switch
    }//end for i
    //cout << "redCount = " << redCount << "  whiteCount = " << whiteCount << " blueCount = " << blueCount << endl;

    int offset = 0;
    for(int i = offset ; i < redCount ;i++){
        nums[i] = RED_VALUE;
    }
    offset = redCount;
    for(int i = offset ; i < offset + whiteCount ;i++){
        nums[i] = WHITE_VALUE;
    }
    offset = redCount + whiteCount;
    for(int i = offset ; i < offset + blueCount ;i++){
        nums[i] = BLUE_VALUE;
    }
}

int main(){
    vector<int> nums={2};
    sortColors(nums);

    for(int &v : nums){
        cout << v << " ";
    }
    cout << endl;
    return 0;
}