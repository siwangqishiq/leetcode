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

void travelTree(TreeNode *node , vector<int> &data){
    if(node == nullptr){
        return;
    }

    travelTree(node->left , data);
    data.push_back(node->val);
    travelTree(node->right , data);
}

bool isValidBST(TreeNode *root) {
    vector<int> data;
    travelTree(root , data);

    for(int i = 0 ; i < data.size() - 1;i++){
        if(data[i] > data[i + 1]){
            return false;
        }
    }//end for i

    return true;
}

int main(){
    return 0;
}



