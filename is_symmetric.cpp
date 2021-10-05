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

bool isSymmetricTree(TreeNode *root){
    if(root == nullptr)
        return true;
    
    if(root->left == nullptr && root->right == nullptr){
        return true;
    }else if(root->left == nullptr && root->right != nullptr 
            || root->left != nullptr && root->right == nullptr ){
        return false;
    }else{ 
        TreeNode *leftNode = root->left;
        TreeNode *rightNode = root->right;

        if(leftNode->left == nullptr && leftNode->right == nullptr 
            && rightNode->left == nullptr && rightNode->right == nullptr ){
                return true;
            }

        return root->left->val == root->right->val
            && isSymmetricTree(root->left) 
            && isSymmetricTree(root->right);
    }

}

bool isSymmetric(TreeNode* root) {
    vector<int> treeElements;
    //i 
    // i + 1 , i + 2 

    return isSymmetricTree(root);
}

int main(){
    return 0;
}