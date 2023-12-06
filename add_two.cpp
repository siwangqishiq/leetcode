#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    auto pLeft = l1;
    auto pRight = l2;

    int prior = 0;
    bool isHead = true;
    ListNode* priorNode = nullptr;
    ListNode* resultHeadNode = nullptr;

    while(pLeft != nullptr || pRight != nullptr){
        auto nodeLeft = pLeft;
        auto nodeRight = pRight;
        
        int newValue = (nodeLeft == nullptr?0:nodeLeft->val) + (nodeRight == nullptr?0:nodeRight->val) + prior;
        if(newValue >= 10){
            newValue -= 10;
            prior = 1;
        }else{
            prior = 0;
        }

        ListNode* addedNode = nodeLeft;
        if(addedNode == nullptr){
            addedNode = nodeRight;
        }
        addedNode->val = newValue;

        if(priorNode != nullptr){
            priorNode->next = addedNode;
        }else{
            resultHeadNode = addedNode;
        }
        priorNode = addedNode;

        if(pLeft != nullptr){
            pLeft = pLeft->next;
        }
        if(pRight != nullptr){
            pRight = pRight->next;
        }
    }//end while

    if(prior != 0){
        ListNode *node = new ListNode(prior);
        node->next = nullptr;
        if(priorNode != nullptr){
            priorNode->next = node;
        }
    }

    return resultHeadNode;        
}


int main(){
    return 0;
}



