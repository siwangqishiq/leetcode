
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *head){
    auto p = head;
    cout << "[";
    while(p != nullptr){
        cout << p->val << " ";
        p = p->next;
    }//end while
    cout <<  "]" << endl; 
}

ListNode* reverseList(ListNode* head) {
    if(head == nullptr){
        return nullptr;
    }

    vector<ListNode *> nodeList;
    auto p = head;
    while(p != nullptr){
        nodeList.push_back(p);
        p = p->next;
    }//end while

    ListNode* newHead = nullptr;
    for(int i = nodeList.size() - 1 ;  i >=0 ;i--){
        ListNode* curNode = nodeList[i];
        if(newHead == nullptr){
            newHead = curNode;
        }
        
        if(i - 1 >= 0){
            curNode->next = nodeList[i - 1];
        }else{
            curNode->next = nullptr;
        }
    }//end for i;
    return newHead;
}

int main(){
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);

    ListNode *head = &node1;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = nullptr;

    printList(head);

    head = reverseList(head);
    printList(head);
    return 0;
}