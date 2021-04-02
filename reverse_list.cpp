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

ListNode* reverseList(ListNode* head) {
    if(head == nullptr)
        return head;
    
    vector<ListNode *> list;
    ListNode *p = head;
    while(p != nullptr){
        list.push_back(p);
        p = p->next;
    }//end while

    ListNode *newHead = nullptr;
    p = nullptr;
    ListNode *prior = nullptr;
    for(int i = list.size() - 1 ; i >= 0;i--){
        p = list[i];
        p->next = nullptr;

        if(i == list.size() - 1){
            newHead = list[i];
        }
        
        if(prior != nullptr){
            prior->next = p;
        }
        prior = p;
    }//end for i

    return newHead;        
}

void printList(ListNode *head){
    ListNode *p = head;
    while(p != nullptr){
        cout << p->val << "  ";
        p = p->next;
    }//end while
    cout << endl;
}

int main(){
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = nullptr;

    printList(&n1);

    ListNode *newHead = reverseList(&n1);

    printList(newHead);

    return 0;
}
 