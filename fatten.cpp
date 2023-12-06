/**
 * @file fatten.cpp
 * 
 * 给你二叉树的根结点 root ，请你将它展开为一个单链表：

展开后的单链表应该同样使用 TreeNode ，
其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */



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

vector<TreeNode *> visitTreePreOrder(TreeNode *node){
    vector<TreeNode *> result;
    
    if(node == nullptr){
        return result;
    }

    result.push_back(node);

    auto leftResult = visitTreePreOrder(node->left);
    if(!leftResult.empty()){
        result.insert(result.end() , leftResult.begin() , leftResult.end());
    }
    auto rightResult = visitTreePreOrder(node->right);
    if(!rightResult.empty()){
        result.insert(result.end() , rightResult.begin() , rightResult.end());
    }
    return result;
}

void flatten(TreeNode* root) {
    vector<TreeNode *> list = visitTreePreOrder(root);

    if(list.empty()){
       return; 
    }

    for(int i = 0 ; i < list.size() - 1;i++){
        TreeNode *node = list.at(i);
        node->right = list.at(i + 1);
        node->left = nullptr;
    }
    
    if(!list.empty()){
        list.at(list.size() - 1)->right = nullptr;
        list.at(list.size() - 1)->left = nullptr;
    }
}

int main(){
    flatten(nullptr);
    return 0;
}
