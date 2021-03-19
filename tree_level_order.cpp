#include <iostream>
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

void treeVisit(TreeNode *root , int level , map<int , vector<int>> &records){
    if(root == nullptr)
        return;

    treeVisit(root->left , level + 1 , records);
    
    if(records.find(level) == records.end()){
        vector<int> vec;
        records[level] = vec;
    }
    records[level].push_back(root->val);

    treeVisit(root->right , level + 1 , records);
}

vector<vector<int>> levelOrder(TreeNode* root) {
    map<int , vector<int>> records;

    treeVisit(root , 0 , records);
    
    vector<vector<int>> result;

    for(auto p:records){
        result.push_back(p.second);
    }//end for each

    return result;
}

/**
 *  3
   / \
  9  20
    /  \
   15   7
 * */
int main(){

    TreeNode *t1 = new TreeNode();
    t1->val = 3;
    
    TreeNode *t2 = new TreeNode();
    t2->val = 9;

    t1->left = t2;

    TreeNode *t3 = new TreeNode();
    t3->val = 20;
    t1->right = t3;

    TreeNode *t4 = new TreeNode();
    t4->val = 15;
    t3->left = t4;

    TreeNode *t5 = new TreeNode();
    t5->val = 7;
    t3->right = t5;

    vector<vector<int>> result = levelOrder(t1);

    for(vector<int> &v : result){
        for(int &val : v){
            cout << " " << val;
        }
        cout << endl;
    }//end for each

    return 0;
}