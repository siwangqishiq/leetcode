
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <string>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void printBinaryTree(TreeNode *head){
    if(head == nullptr){
        return;
    }

    deque<TreeNode *> nodeQueue;
    nodeQueue.push_back(head);

    while(!nodeQueue.empty()){
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop_front();

        cout << "value = " << node->val << endl;

        if(node->left != nullptr){
            nodeQueue.push_back(node->left);
        }

        if(node->right != nullptr){
            nodeQueue.push_back(node->right);
        }

    }//end while
}

void printBinaryTree2(TreeNode *head){
    if(head == nullptr){
        return;
    }

    printBinaryTree2(head->left);
    printBinaryTree2(head->right);
    cout << head->val << endl;
}



bool compareBinTree(TreeNode *left , TreeNode *right){
    if(left == nullptr && right == nullptr){
        return true;
    }else if((left == nullptr && right != nullptr) || (left != nullptr && right == nullptr)){
        return false;
    }else if(left->val != right->val){
        return false;
    }
    return compareBinTree(left->left , right->left) && compareBinTree(left->right , right->right);
}

void preOrderTree(TreeNode *tree , vector<int> &result , map<TreeNode* , int> &idxMap){
    if(tree == nullptr){
        return;
    }

    result.push_back(idxMap[tree]);
    preOrderTree(tree->left , result ,idxMap);
    preOrderTree(tree->right , result ,idxMap);
}

void midOrderTree(TreeNode *tree , vector<int> &result , map<TreeNode* , int> &idxMap){
    if(tree == nullptr){
        return;
    }

    midOrderTree(tree->left , result ,idxMap);
    result.push_back(idxMap[tree]);
    midOrderTree(tree->right , result , idxMap);
}

TreeNode* restoreBinaryTree(vector<int> preOrder , vector<int> midOrder , map<int , int> &idxMap){
    if(preOrder.empty()){
        return nullptr;
    }

    int value = preOrder.front();

    TreeNode *node = new TreeNode(idxMap[value]);
    

    int index = 0;
    for(;index < midOrder.size();index++){
        if(midOrder[index] == value){
            break;
        }
    }//end for index

    vector<int> subPreOrderLeft = vector<int>(preOrder.begin() + 1 , preOrder.begin() + 1 + index);
    vector<int> subPreOrderRight = vector<int>(preOrder.begin() + 1 + index , preOrder.end());
    
    vector<int> subMidOrderLeft = vector<int>(midOrder.begin() , midOrder.begin() + index);
    vector<int> subMidOrderRight = vector<int>(midOrder.begin() + index + 1 , midOrder.end());

    node->left = restoreBinaryTree(subPreOrderLeft , subMidOrderLeft , idxMap);
    node->right = restoreBinaryTree(subPreOrderRight , subMidOrderRight ,idxMap);
    return node;
}

string vecToString(vector<int> list){
    string str;
    for(int i = 0 ; i < list.size() ;i++){
        str += std::to_string(list[i]);
        if(i != list.size() -1 ){
            str +=",";
        }
    }//end for i
    return str;
}

vector<int> stringToIntVec(string str){
    vector<int> result;
    int index = 0;
    string subStr = "";
    while(index < str.size()){
        if(str[index] == ' '){
            continue;
        }else if(str[index] == ','){
            if(!subStr.empty()){
                int value = std::stoi(subStr.c_str());
                result.push_back(value);
                subStr = "";
            }
        }else{
            subStr += str[index];
        }
        index++;
    }//end while

    if(!subStr.empty()){
        int value = std::stoi(subStr.c_str());
        result.push_back(value);
        subStr = "";
    }
    return result;
}

vector<string> splitString(string &data){
    vector<string> splits;
    int start = 0;
    int index = 0;
    while(index < data.size()){
        if(data[index] == '#'){
            splits.emplace_back(data.begin() + start , data.begin() + index);
            start = index + 1;
        }
        index++;
    }//end while

    splits.emplace_back(data.begin() + start , data.end());
    return splits;
}

string treeIndexed(TreeNode *root ,  map<TreeNode *, int> &nodeIdxMap){
    string idxStr;
    if(root == nullptr){
        return idxStr;
    }
    
    map<int , int> treeIndexMap;
    deque<TreeNode *> queue;
    queue.push_back(root); 
    int index = 0;
    while(!queue.empty()){
        TreeNode *node = queue.front();
        queue.pop_front();

        nodeIdxMap[node] = index;
        treeIndexMap[index++] = node->val;
        

        if(node->left != nullptr){
            queue.push_back(node->left);
        }

        if(node->right != nullptr){
            queue.push_back(node->right);
        }
    }//end while

    string keyStr = "";
    string valueStr = "";
    for(auto p: treeIndexMap){
        // cout << p.first << " = " <<p.second <<endl;
        keyStr += std::to_string(p.first);
        keyStr += ",";

        valueStr += std::to_string(p.second);
        valueStr += ",";
    }
    keyStr.erase(keyStr.end() - 1);
    valueStr.erase(valueStr.end() - 1);
    return keyStr +"#" + valueStr;
}

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if(root == nullptr){
        return "";
    }

    map<TreeNode* , int> idxMap;
    std::string idxString = treeIndexed(root , idxMap);
    
    vector<int> preOrder;
    preOrderTree(root , preOrder , idxMap);

    vector<int> midOrder;
    midOrderTree(root , midOrder , idxMap);

    return vecToString(preOrder) + "#" + vecToString(midOrder) + "#" + idxString;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data.empty()){
        return nullptr;
    }
    
    vector<string> splits = splitString(data);
    vector<int> preOrder = stringToIntVec(splits[0]);
    vector<int> midOrder = stringToIntVec(splits[1]);
    vector<int> idx = stringToIntVec(splits[3]);

    map<int , int> idxMap;
    for(int i = 0 ; i < idx.size() ; i++){
        idxMap[i] = idx[i];
    }//end for i

    return restoreBinaryTree(preOrder , midOrder , idxMap);
}

int main(){
    // TreeNode node1(1);
    // TreeNode node2(2);
    // TreeNode node3(3);
    // TreeNode node4(4);
    // TreeNode node5(5);

    // node1.left = &node2;
    // node1.right = &node3;

    // node3.left = &node4;
    // node3.right = &node5;


    TreeNode node1(3);
    TreeNode node2(2);
    TreeNode node3(4);
    TreeNode node4(3);

    node1.left = &node2;
    node1.right = &node3;

    node2.left = &node4;

    // printBinaryTree2(&node1);
    // cout << compareBinTree(&node1 , &node5) << endl;
    // cout << serialize(&node1) << endl;

    // vector<int> midOrder;
    // midOrderTree(&node1 , midOrder);
    // vector<int> preOrder;
    // preOrderTree(&node1 , preOrder);

    // auto restoreTree = restoreBinaryTree(preOrder , midOrder);
    // printBinaryTree2(restoreTree);

    // for(auto v : preOrder){
    //     cout << v << endl;
    // }

    string serializeString = serialize(&node1);
    cout << "serialize = " << serializeString << endl;
    // vector<string> splits = splitString(serializeString);
    // cout << "spli1 = " << splits[0] << endl;
    // cout << "spli2 = " << splits[1] << endl;
    // cout << "spli3 = " << splits[2] << endl;
    // cout << "spli4 = " << splits[3] << endl;

    // string treeStr = serialize(&node1);
    TreeNode *treeNode = deserialize(serializeString);
    printBinaryTree(treeNode);

    // cout << treeIndexed(&node1) << endl;
    // cout << serialize(&node1) << endl;
    return 0;
}


