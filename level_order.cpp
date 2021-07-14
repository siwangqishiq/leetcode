/**
 * 
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 
 * （即逐层地，从左到右访问所有节点）。

 

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层序遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */

#include <iostream>
#include <list>
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

void visitBinaryTree(TreeNode *treeNode , int deep , map<TreeNode * , int> &deepMap){
    if(treeNode == nullptr)
        return;
    
    deepMap[treeNode] = deep;

    if(treeNode->left != nullptr){
        visitBinaryTree(treeNode->left , deep + 1 , deepMap);
    }

    if(treeNode->right != nullptr){
        visitBinaryTree(treeNode->right , deep + 1 , deepMap);
    }
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if(root == nullptr)
        return result;

    map<TreeNode * , int> deepMap;
    visitBinaryTree(root , 0 , deepMap);


    int lastDeep = -1;
    vector<int> content;
    for(auto it = deepMap.rbegin();it != deepMap.rend(); it++){
        auto p = *it;
        //cout << p.second << " : " << p.first->val << endl;

        if(p.second != lastDeep){
            if(!content.empty()){
                result.push_back(content);
            }
            content.clear();
            lastDeep = p.second;
        }
        content.push_back(p.first->val);
    }//end for each

    if(!content.empty()){
        result.push_back(content);
    }

    return result;
}


int main(){

    /**
     3*         
   / \
  9  20
    /  \
   15   7
     * */

    TreeNode node3(3);
    TreeNode node9(9);
    TreeNode node20(20);
    TreeNode node15(15);
    TreeNode node7(7);

    node3.left = &node9;
    node3.right = &node20;

    node20.left = &node15;
    node20.right = &node7;

    vector<vector<int>> result = levelOrder(&node3);

    for(vector<int> &vec : result){
        for(int &v : vec){
            cout << v << " ";
        }
        cout << endl;
    }
    
    return 0;
}
