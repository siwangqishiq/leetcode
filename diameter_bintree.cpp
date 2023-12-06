

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int diameterBTree(TreeNode *node){
    if(node == nullptr){
        return 0;
    }

    int leftDm = diameterBTree(node->left);
    int rightDm = diameterBTree(node->right);

    int diameter = 1;
    if(node->left != nullptr){
        diameter += leftDm;
    }

    if(node->right != nullptr){
        diameter += rightDm;
    }
    return diameter;
}


int diameterOfBinaryTree(TreeNode* root) {
    return diameterBTree(root);
}

int main(){
    return 0;
}