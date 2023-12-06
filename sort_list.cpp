
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

static bool customSort(ListNode *left, ListNode *right) {
    return left->val < right->val;
}

ListNode* sortList(ListNode* head) {
    vector<ListNode *> list;
    auto p = head;
    while(p != nullptr){
        list.push_back(p);
        p = p->next;
    }//end while

    if(list.empty()){
        return nullptr;
    }

    std::sort(list.begin() , list.end() , customSort);

    ListNode *newHead = nullptr;
    ListNode *prior = nullptr;
    for(int i = 0 ;  i < list.size() ;i++){
        auto node = list[i];
        if(newHead == nullptr){
            newHead = node;
        }

        if(prior != nullptr){
            prior->next = node;
        }

        prior = node;
        node->next = nullptr;
    }//end for i
    return newHead;
}

int main(){
    return 0;
}

