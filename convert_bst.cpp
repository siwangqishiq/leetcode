#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void traceBinaryTree(TreeNode* root, vector<int> &treeArray) {
    if(root == nullptr){
        return;
    }

    traceBinaryTree(root->left, treeArray);
    treeArray.push_back(root->val);
    traceBinaryTree(root->right,  treeArray);
}

void visitAndSetTree(TreeNode* root, map<int, int> &sumMap){
    if(root == nullptr){
        return;
    }

    visitAndSetTree(root->left, sumMap);
    root->val = sumMap[root->val];
    visitAndSetTree(root->right, sumMap);
}

TreeNode* convertBST(TreeNode* root) {
    vector<int> treeArray;
    traceBinaryTree(root, treeArray);

    vector<int> sumArray(treeArray.size());
    int sum = 0;
    for(int i = 0; i < treeArray.size() ; i++ ){
        sum += treeArray[i];
        sumArray[i] = sum;
    }//end for i

    map<int, int> sumMap;
    for(int i = 0; i < treeArray.size() ; i++ ){
        sumMap[treeArray[i]] = sumArray[sumArray.size() - 1] - sumArray[i] + treeArray[i];
    }//end for i
    visitAndSetTree(root, sumMap);
    return root;
}

int main() {
    TreeNode n0(0);
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);
    TreeNode n7(7);
    TreeNode n8(8);

    TreeNode *root = &n4;
    n4.left = &n1;
    n1.left = &n0;
    n1.right = &n2;
    n2.right = &n3;

    n4.right = &n6;
    n6.left = &n5;
    n6.right = &n7;
    n7.right = &n8;


    // traceBinaryTree(root);
    convertBST(root);


    return 0;
}