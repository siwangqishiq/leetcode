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

vector<int> convertTreeToVec(TreeNode* root){
    vector<int> result;
    if(root == nullptr){
        return result;
    }

    if(root->left != nullptr){
        vector<int> leftVec = convertTreeToVec(root->left);
        result.insert(result.begin(), leftVec.begin(), leftVec.end());
    }

    result.push_back(root->val);

    if(root->right != nullptr){
        vector<int> rightVec = convertTreeToVec(root->right);
        result.insert(result.end(), rightVec.begin(), rightVec.end());
    }
    return result;
}

TreeNode* buildBstTree(vector<int> &data, int start, int end){
    // std::cout << "start = " << start << "\tend = " << end << std::endl;
    if(end <= start){
        return nullptr;
    }

    int mid = (start + end)/2;
    int value = data[mid];
    TreeNode *node = new TreeNode(value);
    if(end - start == 1){
        return node;
    }

    TreeNode *left = buildBstTree(data, start, mid);
    TreeNode *right = buildBstTree(data,mid + 1, end);
    node->left = left;
    node->right = right;
    return node;
}

TreeNode* buildBstTree(vector<int> &data){
    return buildBstTree(data, 0, data.size());
}

TreeNode* balanceBST(TreeNode* root) {
    vector<int> data = convertTreeToVec(root);
    return buildBstTree(data);    
}

void printTree(TreeNode *node){
    if(node == nullptr){
        return;
    }

    printTree(node->left);
    cout << node->val << "  ";
    printTree(node->right);
}

void test_buildBstTree(){
    vector<int> data = {1};
    auto treeNode = buildBstTree(data);
    printTree(treeNode);
    std::cout << std::endl;
}

void test_convertTreeToVec(){
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    node2.left = &node1;
    node2.right = &node3;
    node3.right = &node4;

    auto result = convertTreeToVec(&node2);
    for(auto v : result){
        std::cout << v << "   ";
    }//end for 
}


int main(){
    // test_convertTreeToVec();
    test_buildBstTree();
    return 0;
}