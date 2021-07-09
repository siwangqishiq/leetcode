/**
 * 
 * 给定一个二叉树，返回其节点值的锯齿形层序遍历。
 * （即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层序遍历如下：

[
  [3],
  [20,9],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 * */

#include <iostream>
#include <vector>
#include <list>
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

void visitBinaryTree(TreeNode *node ,int deep , map<int , vector<int>> &orderMap){
    if(node == nullptr)
        return;
    
    if(orderMap.find(deep) == orderMap.end()){
        vector<int> elements;
        elements.push_back(node->val);

        orderMap[deep] = elements;
    }else{
        vector<int> elements = orderMap[deep];
        elements.push_back(node->val);

        orderMap[deep] = elements;
    }//end if

    visitBinaryTree(node->left , deep + 1 , orderMap);
    visitBinaryTree(node->right , deep + 1 , orderMap);
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;

    if(root == nullptr)
        return result;

    map<int , vector<int>> orderMap;
    visitBinaryTree(root , 0 , orderMap);

    // for(auto p : orderMap){
    //     cout << p.first << " -> " ;
    //     for(int &v : p.second){
    //         cout << " " << v;
    //     }//end for each
    //     cout << endl;
    // }

    bool ltr = true;
    for(auto p : orderMap){
        if(ltr){
            result.push_back(p.second);
        }else{//reverse
            vector<int> reverseList;
            vector<int> list = p.second;
            for(int i = list.size() -1 ;i >=0;i--){
                reverseList.push_back(list[i]);
            }//end for i

            result.push_back(reverseList);
        }
        ltr = !ltr;
    }

    return result;
}

/**
 *     
    3
   / \
  9  20
    /  \
   15   7

 * */

int main(){

    TreeNode node3(3);
    TreeNode node9(9);
    TreeNode node20(20);
    TreeNode node15(15);
    TreeNode node7(7);

    TreeNode node8(8);

    node3.left = &node9;
    node3.right = &node20;
    node20.left = &node15;
    node20.right = &node7;

    node7.right = &node8;

    vector<vector<int>> result = zigzagLevelOrder(&node3);

    for(auto &vec : result){
        for(int &v : vec){
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}
