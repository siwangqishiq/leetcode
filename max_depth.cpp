

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int findNodeDepth(TreeNode *node){
    if(node == nullptr){
        return 0;
    }

    int depth = 1;
    int leftDepth = findNodeDepth(node->left);
    int rightDepth = findNodeDepth(node->right);
    if(leftDepth > rightDepth){
        depth += leftDepth;
    }else{
        depth += rightDepth;
    }
    return depth;
}

int maxDepth(TreeNode* root) {
    return findNodeDepth(root);
}

int main(){
    return 0;
}
