

#include <iostream>
#include <vector>
#include <map>


using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void findTreeAncestor(TreeNode *node , map<TreeNode * , TreeNode *> &parentNodeMap){
    if(node != nullptr){
        if(node->left != nullptr){
            parentNodeMap[node->left] = node;

            findTreeAncestor(node->left , parentNodeMap);            
        }

        if(node->right != nullptr){
            parentNodeMap[node->right] = node;

            findTreeAncestor(node->right , parentNodeMap); 
        }
    }
}

void findNodeAncestors(map<TreeNode* , TreeNode*> &parentNodeMap , vector<TreeNode *> &result , TreeNode *startNode){
    TreeNode *p = startNode;

    while(p != nullptr){
        result.push_back(p);

        if(parentNodeMap.find(p) == parentNodeMap.end()){
            p = nullptr;
        }else{
            p = parentNodeMap[p];
        }
    }//end while
}

TreeNode* searchSameElement(vector<TreeNode *> &leftVec , vector<TreeNode *> &rightVec){
    for(int i = 0 ; i < rightVec.size();i++){
        for(int j = 0; j < leftVec.size() ; j++){
            if(rightVec[i] == leftVec[j])
                return leftVec[j];
        }//end for j
    }
    return nullptr;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    map<TreeNode* , TreeNode*> parentNodeMap;
    findTreeAncestor(root , parentNodeMap);

    vector<TreeNode *> pNodeAncestors;
    findNodeAncestors(parentNodeMap , pNodeAncestors , p);

    vector<TreeNode *> qNodeAncestors;
    findNodeAncestors(parentNodeMap , qNodeAncestors , q);

    if(pNodeAncestors.size() <= qNodeAncestors.size()){
        return searchSameElement(pNodeAncestors , qNodeAncestors);
    }

    return searchSameElement(qNodeAncestors , pNodeAncestors);
}

int main(){
    TreeNode node3(3);

    TreeNode node5(5);

    TreeNode node1(1);

    node3.left = &node5;
    node3.right = &node1;

    TreeNode node6(6);

    node5.left = &node6;

    TreeNode node2(2);

    node5.right = &node2;

    TreeNode node7(7);
    TreeNode node4(4);

    node2.left = &node7;
    node2.right = &node4;

    TreeNode node0(0);
    TreeNode node8(8);

    node1.left = &node0;
    node1.right = &node8;

    TreeNode *ancestor = lowestCommonAncestor(&node3 , &node5 , &node4);

    cout << "ancestor = " << ancestor->val << endl;
    return 0;
}
