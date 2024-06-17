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

int max(int a , int b){
    return a >=b ?a :b;
}

int findBinTreeDepth(TreeNode *node,int &diameter){
    if(node == nullptr){
        return 0;
    }

    int leftTreeDepth = findBinTreeDepth(node->left , diameter);
    int rightTreeDepth = findBinTreeDepth(node->right , diameter);

    if(diameter < leftTreeDepth + rightTreeDepth){
        diameter = leftTreeDepth + rightTreeDepth;
    }

    int depth = max(leftTreeDepth , rightTreeDepth);
    return depth + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    findBinTreeDepth(root , diameter);
    return diameter;        
}

int main(){
    return 0;
}


