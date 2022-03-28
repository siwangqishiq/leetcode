#include <iostream>
#include <unordered_map>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_map<ListNode *, int> hash;
    
    ListNode *p = headA;
    while(p != nullptr){
        hash[p] = p->val;
        p = p->next;
    }//end while

    p = headB;
    while(p != nullptr){
        if(hash.find(p) != hash.end()){
            return p;
        }
        p = p->next;
    }//end while
    
    return nullptr;
}


int main(){
    return 0;
}