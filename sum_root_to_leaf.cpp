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

int calBinVec(vector<int> bins){
    int result = 0;

    // for(auto &v : bins){
    //     cout << v <<" ";
    // }
    // cout << std::endl;

    for(int i = 0 ; i < bins.size() ; i++){
        result = result << 1;

        if(bins[i] == 1){
            result += 1;
        }
    }//end for i

    // cout << "sumvalue = " << result << std::endl;
    return result;
}

void visitTree(TreeNode *node, vector<int> preVec, int &sumValue){
    if(node == nullptr){
        return;
    }
    
    vector<int> result = preVec;

    result.push_back(node->val);
    if(node->left == nullptr && node->right == nullptr){
        sumValue += calBinVec(result);
    }else{
        visitTree(node->left, result, sumValue);
        visitTree(node->right, result, sumValue);
    }
}

int sumRootToLeaf(TreeNode* root) {
    int sumValue = 0;
    vector<int> values;
    visitTree(root, values, sumValue);
    return sumValue;
}

int main(){
    TreeNode root(1);
    TreeNode n1(0);
    TreeNode n2(1);
    TreeNode n3(0);
    TreeNode n4(1);
    TreeNode n5(0);
    TreeNode n6(1);

    root.left = &n1;
    root.right = &n2;

    n1.left = &n3;
    n1.right = &n4;

    n2.left = &n5;
    n2.right = &n6;

    auto result = sumRootToLeaf(&root);
    std::cout << "result = " << result << std::endl;


    vector<int> data = {1,0,0};
    std::cout << calBinVec(data) << std::endl;
    return 0;
}