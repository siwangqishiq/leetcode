#include <iostream>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == nullptr && q == nullptr){
        return true;
    }else if(p != nullptr && q != nullptr){
        return p->val == q->val && isSameTree(p->left , q->left) && isSameTree(p->right , q->right);
    }else{
        return false;
    }
}

bool isSymmetric(TreeNode* root) {
    if(root == nullptr)
        return true;
    
    if(root->left != nullptr && root->right != nullptr){
        return  
    }
}

int main(){
    return 0;
}

