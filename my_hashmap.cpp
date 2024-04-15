#include <iostream>
#include <vector>

using namespace std;

class Node{
public:
    int key;
    int value;
};

class MyHashMap {
public:
    MyHashMap() {
        mNodeArray = vector<vector<Node *> *>(ARRAY_SIZE);
    }

    ~MyHashMap(){
        for(int i = 0 ; i < mNodeArray.size() ;i++){
            vector<Node *> *nodeList = mNodeArray[i];
            if(nodeList != nullptr){
                for(int j = 0 ; j < nodeList->size();j++){
                    Node *node = nodeList->at(j);
                    if(node != nullptr){
                        delete node;
                        node = nullptr;
                    }
                }//end for j
            }
            delete nodeList;
        }//end for i
    }
    
    void put(int key, int value) {
        int hashCode = hash(key);
        vector<Node *> *nodeList = mNodeArray[hashCode];

        if(nodeList == nullptr){
            nodeList = new vector<Node*>();
            mNodeArray[hashCode] = nodeList;

            Node *node = new Node();
            node->key = key;
            node->value = value;
            nodeList->push_back(node);
        }else{
            for(int i = 0 ; i < nodeList->size();i++){
                Node *node = nodeList->at(i);
                if(node->key == key){
                    node->value = value;
                    return;
                }
            }//end for i
            
            //not fund
            Node *node = new Node();
            node->key = key;
            node->value = value;
            nodeList->push_back(node);
        }
    }
    
    int get(int key) {
        int hashCode = hash(key);
        vector<Node *> *nodeList = mNodeArray[hashCode];
        if(nodeList == nullptr){
            return -1;
        }

        for(int i = 0 ; i < nodeList->size();i++){
            Node *node = nodeList->at(i);
            if(node->key == key){
                return node->value;
            }
        }//end for i
        return -1;
    }
    
    void remove(int key) {
        int hashKey = hash(key);
        vector<Node *> *nodeList = mNodeArray[hashKey];
        if(nodeList == nullptr){
            return;
        }

        for(auto iter = nodeList->begin() ; iter < nodeList->end();iter++){
            Node *node = *iter;
            if(node != nullptr && node->key == key){
                nodeList->erase(iter);
            }
        }//end for iter
    }

private:
    const int ARRAY_SIZE = 1024;
    vector<vector<Node*> *> mNodeArray;

    int hash(int value){
        return value % ARRAY_SIZE;
    }
};

int main(){
    MyHashMap myMap;
    myMap.put(1,1);
    myMap.put(2,2);
    myMap.put(3,3);

    cout << myMap.get(1) << endl;
    cout << myMap.get(2) << endl;
    cout << myMap.get(3) << endl;

    myMap.remove(2);
     cout << myMap.get(1) << endl;
    cout << myMap.get(2) << endl;
    cout << myMap.get(3) << endl;

    return 0;
}




