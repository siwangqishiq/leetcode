
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


void travelBinaryTree(TreeNode *root ,int preSum, vector<int> &leafNodeValues){
    if(root == nullptr){
        return;
    }

    int sum = preSum << 1;
    if(root->val == 1){
        sum += 1;
    }

    if(isLeaf(root)){
        leafNodeValues.push_back(sum);
    }else{
        travelBinaryTree(root->left , sum , leafNodeValues);
        travelBinaryTree(root->right , sum , leafNodeValues);
    }
}

bool isLeaf(TreeNode *node){
    return node != nullptr && node->left == nullptr && node->right == nullptr;
}

int sumRootToLeaf(TreeNode* root) {
    vector<int> leafNodeValues;
    int sum = 0;

    travelBinaryTree(root , sum , leafNodeValues);

    int result = 0;
    for(int v : leafNodeValues){
        //cout << v << "  ";
        result += v;
    }//end for each
    cout << endl;

    return result;
}

int main(){
    return 0;
}


