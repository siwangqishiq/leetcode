
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// vector<int> dailyTemperatures(vector<int>& temperatures) {
//     vector<int> result;
//     if(temperatures.empty()){
//         return result;
//     }

//     if(temperatures.size() <= 1){
//         result.push_back(0);
//         return result;
//     }

//     result.resize(temperatures.size());
//     for(int i = 0 ; i < temperatures.size(); i++){
//         const int temperatureValue = temperatures[i];
//         int index = 0;
//         bool findHigher = false;
//         for(int j = i + 1;j < temperatures.size();j++){
//             index++;
//             if(temperatures[j] > temperatureValue){
//                 findHigher = true;
//                 break;
//             }
//         }//end for j
//         result[i] = findHigher?index:0;
//     }//end for i
//     return result;
// }

vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> result;
    if(temperatures.empty()){
        return result;
    }

    if(temperatures.size() <= 1){
        result.push_back(0);
        return result;
    }

    vector<int> sortedTemp(temperatures.begin() , temperatures.end());
    std::sort(sortedTemp.begin() , sortedTemp.end());

    map<int, int> sortMap;
    for(int i = 0 ; i < sortedTemp.size();i++){
        sortMap[sortedTemp[i]] = i;
    }//end for i


    return result;
}


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 TreeNode *treeMerge(TreeNode *leftTree , TreeNode *rightTree){
     if(leftTree == nullptr && rightTree == nullptr){
        return nullptr;
     }else if(leftTree == nullptr && rightTree != nullptr){
        return rightTree;
     }else if(leftTree != nullptr && rightTree == nullptr){
        return leftTree;
     }else{
        TreeNode *newLeftTree = treeMerge(leftTree->left , rightTree->left);
        TreeNode *newRightTree = treeMerge(leftTree->right , rightTree->right);

        leftTree->val += rightTree->val;
        leftTree->left = newLeftTree;
        leftTree->right = newRightTree;
        return leftTree;
     }
 }

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    return treeMerge(root1 , root2);
}

int main(){

    return 0;
}

