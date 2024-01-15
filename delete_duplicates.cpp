/**
 * @file delete_duplicates.cpp

 https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *buildLinkedListFromVector(vector<ListNode *> &nodeList){
    if(nodeList.empty()){
        return nullptr;
    }

    ListNode *head = nullptr;
    ListNode *preNode = nullptr;
    for(ListNode *node : nodeList){
        if(head == nullptr){
            head = node;
        }

        node->next = nullptr;
        if(preNode != nullptr){
            preNode->next = node;
        }
        preNode = node;
    }//end for each
    return head;
}

ListNode* deleteDuplicates(ListNode* head) {
    vector<ListNode *> nodeList;

    ListNode *p = head;
    unordered_map<int,  int> hashSet;
    while(p != nullptr){
        if(hashSet.find(head->val) == hashSet.end()){
            hashSet[p->val] = 1;
        }else{
            hashSet[p->val] = hashSet[p->val] + 1;
        }
        p = p->next;
    }//end while
    

    p = head;
    while(p != nullptr){
        if(hashSet[p->val] == 1){
            nodeList.push_back(p);
        }
        p = p->next;
    }//end while
    // cout << "nodeList cout = " << nodeList.size() << endl;
    return buildLinkedListFromVector(nodeList);
}

void print(ListNode *p){
    while(p){
        cout << p->val << endl;
        p = p->next;
    }//end while
}

int main(){
    //1,2,3,3,4,4,5
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(3);
    ListNode node5(4);
    ListNode node6(4);
    ListNode node7(5);

    ListNode *head = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;
    node7.next = nullptr;

    auto p = deleteDuplicates(head);
    print(p);

    return 0;
}
