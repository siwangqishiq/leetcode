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

bool isSymmetricTree(TreeNode *left , TreeNode *right){
    if(left == nullptr && right == nullptr){
        return true;
    }else if(left != nullptr && right == nullptr){
        return false;
    }else if(left == nullptr && right != nullptr){
        return false;
    }else{
        return (left->val == right->val) 
            && isSymmetricTree(left->left , right->right)
            && isSymmetricTree(left->right , right->left);
    }
}

bool isSymmetric(TreeNode* root) {
    if(root == nullptr){
        return true;
    }
    return isSymmetricTree(root->left , root->right);
}

int main(){
    return 0;
}