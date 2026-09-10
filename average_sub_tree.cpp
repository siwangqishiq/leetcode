#include <iostream>
#include <vector>
#include <map>
#include <array>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int findTreeMapNodeValue(map<TreeNode *, array<int, 2>> &treeMap, TreeNode *node, bool isFirst){
    if(node == nullptr){
        return 0;
    }

    if(treeMap.find(node) == treeMap.end()){
        return 0;
    }

    return treeMap[node][isFirst?0:1];
}

void visitTree(TreeNode* node, map<TreeNode *, array<int, 2>> &treeMap){
    if(node == nullptr){
        return;
    }

    array<int, 2> countAndSum;
    
    auto left = node->left;
    visitTree(left, treeMap);

    auto right = node->right;
    visitTree(right, treeMap);

    countAndSum[0] = findTreeMapNodeValue(treeMap, left, true) + findTreeMapNodeValue(treeMap, right, true) + 1;
    countAndSum[1] = findTreeMapNodeValue(treeMap, left, false) + findTreeMapNodeValue(treeMap, right, false) + node->val;

    treeMap[node] = countAndSum;
}

int averageOfSubtree(TreeNode* root) {
    map<TreeNode *, array<int, 2>> treeMap;
    visitTree(root, treeMap);

    int retCount = 0;
    for(auto &p : treeMap){
        if(p.second[1] / p.second[0] == p.first->val){
            retCount++;
        }
    }
    return retCount;
}

int main(){
    // TreeNode node{1};
    // int ret = averageOfSubtree(&node);

    TreeNode root{4};

    TreeNode node8{8};
    TreeNode node5{5};

    TreeNode node0{0};
    TreeNode node1{1};
    TreeNode node6{6};

    root.left = &node8;
    root.right = &node5;
    node8.left = &node0;
    node8.right = &node1;
    node5.right = &node6;

    int ret = averageOfSubtree(&root);

    std::cout << "result = " << ret << std::endl;
    return 0;
}