
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildBst(vector<int>& nums, int left , int right){
    if(right - left <= 0){
        return nullptr;
    }

    const int mid = left + (right - left) / 2;

    TreeNode *rootNode = new TreeNode(nums[mid]);

    TreeNode *leftChild = buildBst(nums, left , mid);
    rootNode->left = leftChild;

    TreeNode *rightChild = buildBst(nums, mid + 1 , right);
    rootNode->right = rightChild;

    return rootNode;   
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return buildBst(nums, 0, nums.size());
}

void printTree(TreeNode *root){
    if(root != nullptr){
        printTree(root->left);
        std::cout << root->val << " ";
        printTree(root->right);
    }else{
        std::cout << "null ";
    }
}

int main(){
    vector<int> nums = {1,2,3,4,5,6};
    auto root = sortedArrayToBST(nums);
    printTree(root);
    return 0;
}

