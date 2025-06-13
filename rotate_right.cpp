#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printLinkedList(ListNode *head){
    auto p = head;
    while(p != nullptr){
        cout << p->val << "   ";
        p = p->next;
    }//end while
    cout <<endl;
}

ListNode *findLastNode(ListNode *head, ListNode *prior){
    if(head == nullptr){
        return head;
    }

    ListNode* p = head;
    prior = nullptr;
    while(p != nullptr){
        if(p->next == nullptr){
            return p;
        }
        p = p->next;
    }//end while
    return p;
}

// ListNode *rotateRight(ListNode *head,int k){
//     if(k == 0 || head == nullptr){
//         return head;
//     }

//     ListNode *lastNode = findLastNode(head);
//     lastNode->next = head;

//     ListNode *prior = lastNode;
//     ListNode *p = head;
//     int index = 0;
//     while(index < k){
//         prior = p;
//         p = p->next;
//         index++;
//     }//end while
//     if(prior != nullptr){
//         prior->next = nullptr;
//     }
//     return p;
// }

int findLinkListSize(ListNode *head){
    int size = 0;
    ListNode *p = head;
    while(p != nullptr){
        p = p->next;
        size++;
    }
    return size;
}


ListNode *rotateRight(ListNode *head,int k){
    const int linkListSize = findLinkListSize(head);
    if(head == nullptr || k == 0 || linkListSize == 0){
        return head;
    }

    k = k % linkListSize;
    int index = 0;
    while(index < k){
        ListNode *p = head;
        ListNode *prior = nullptr;
        
        while(p->next != nullptr){
            prior = p;
            p = p->next;
        }//end while

        if(prior != nullptr){
            prior->next = nullptr;
            p->next = head;
        }
        
        head = p;

        index++;
    }//end while

    return head;
}

int main(){

    ListNode node1(1);
    ListNode *head = &node1;
    printLinkedList(head);

    auto newHead = rotateRight(head , 1);
    printLinkedList(newHead);


    // for(int i = 1; i <= 4;i++){
    //     ListNode node1(1);
    //     ListNode node2(2);
    //     ListNode node3(3);
    //     ListNode node4(4);
    //     ListNode node5(5);

    //     ListNode *head = &node1;
    //     node1.next = &node2;
    //     node2.next = &node3;
    //     node3.next = &node4;
    //     node4.next = &node5;
        
    //     printLinkedList(head);
    //     // cout << "lst : " << findLastNode(head)->val << endl;

    //     auto newHead = rotateRight(head , i);
    //     printLinkedList(newHead);
    // }
    

    // ListNode node1(0);
    // ListNode node2(1);
    // ListNode node3(2);

    // ListNode *head = &node1;
    // node1.next = &node2;
    // node2.next = &node3;

    // printLinkedList(head);
    // cout << "lst : " << findLastNode(head)->val << endl;

    // auto newHead = rotateRight(head , 4);
    // printLinkedList(newHead);


    
    // ListNode node1(1);
    // ListNode node2(2);

    // ListNode *head = &node1;
    // node1.next = &node2;
    // printLinkedList(head);
    // cout << "lst : " << findLastNode(head)->val << endl;

    // auto newHead = rotateRight(head , 1);
    // printLinkedList(newHead);

    return 0;
}
