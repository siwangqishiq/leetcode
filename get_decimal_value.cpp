
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int getDecimalValue(ListNode* head){
    int value = 0;
    auto p = head;

    while(p != nullptr){
        value = value << 1;
        value += p->val;

        p = p->next;
    }//end while
    return value;
}

int main(){
    ListNode node1(1);
    // ListNode node2(0);
    // ListNode node3(0);

    // node1.next = &node2;
    // node2.next = &node3;

    

    ListNode *head = &node1;
    auto result = getDecimalValue(head);
    
    std::cout << "result = " << result << std::endl;
    return 0;
}


