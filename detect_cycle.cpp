

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head) {
    ListNode *p = head;

    unordered_map<ListNode *, int> nodeMap;

    int index = 0;
    while(p != nullptr){
        if(nodeMap.find(p) != nodeMap.end()){ //found it
            return p;
        }
        nodeMap[p] = index;
        index++;
        p = p->next;
    }

    return nullptr;
}

int main(){
    return 0;
}
