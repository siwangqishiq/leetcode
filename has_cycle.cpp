#include <iostream>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
    map<ListNode* , int> records;

    ListNode *p = head;
    bool hasCircle = false;

    while(p != nullptr){
        if(records.find(p) != records.end()){//has found
            hasCircle = true;
            break;
        }

        records[p] = p->val; 
        p = p->next;
    }//end while
    return hasCircle;        
}

int main(){
    ListNode head(1);
    ListNode n2(2);
    ListNode n3(3);

    head.next = &n2;
    n2.next = &n3;
    
    n3.next = &head;

    auto result = hasCycle(&head);
    cout << "has Circle:" << result << endl;
    return 0;
}