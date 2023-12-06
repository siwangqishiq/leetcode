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

int findValueIndex(vector<int>& order , int value , int start , int end){
    if(order.empty()){
        return -1;
    }

    int index = -1;
    for(int i = start ; i < end ; i++){
        if(order[i] == value){
            index = i;
        }
    }//end for i
    return index;
}

TreeNode* doBuildTree(vector<int>& preorder , int preOrderStart , int preOrderEnd , 
                        vector<int>& inorder , int inorderStart , int inorderEnd){
    // cout << " preOrderStart = " << "[ " << preOrderStart << " , " << preOrderEnd << ") " << " inorderStart = " << "[ " << inorderStart << " , " << inorderEnd << ")" << endl;
    if(preOrderEnd - preOrderStart <= 0 || inorderEnd - inorderStart <= 0 
        || preOrderStart < 0 || preOrderEnd > preorder.size()
        || inorderStart < 0 || inorderEnd > inorder.size()){
        return nullptr;
    }
    
    const int rootValue = preorder[preOrderStart];
    TreeNode *root = new TreeNode(rootValue);
    
    int idxInorder = findValueIndex(inorder , rootValue , inorderStart , inorderEnd);
    // cout << "idxInorder = " << idxInorder << endl;
    if(idxInorder < 0 ){
        return nullptr;
    }
    
    TreeNode *leftTree = doBuildTree(preorder 
                            ,preOrderStart + 1 
                            ,preOrderStart + 1 + idxInorder - inorderStart
                            ,inorder 
                            ,inorderStart
                            ,idxInorder);
    TreeNode *rightTree = doBuildTree(preorder 
                            ,preOrderEnd - inorderEnd + idxInorder + 1
                            ,preOrderEnd
                            ,inorder 
                            ,idxInorder + 1
                            ,inorderEnd);

    root->left = leftTree;
    root->right = rightTree;
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return doBuildTree(preorder , 0  , preorder.size() , 
        inorder , 0, inorder.size());
}

void printBinTree(TreeNode *node){
    if(node == nullptr){
        return;
    }

    cout << node->val << endl;

    printBinTree(node->left);
    printBinTree(node->right);
}

int main(){
    // vector<int> preorder = {3,9,20,15,7};
    // vector<int> inorder = {9,3,15,20,7};

    // vector<int> preorder = {1,2,3};
    // vector<int> inorder = {2,3,1};

    vector<int> preorder = {1};
    vector<int> inorder = {1};
    auto rootNode = buildTree(preorder , inorder);
    printBinTree(rootNode);
    return 0;
}
