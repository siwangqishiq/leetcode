/**
 * 
 * 
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 * */

#include <iostream>

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *p = head;
    if(p == nullptr)
        return nullptr;

    int length = 0;
    while(p != nullptr){
        p = p->next;
        length++;
    }

    p = head;
    int order = length - n;
    int index = 0;
    ListNode *prior = nullptr;

    while(index < order){
        prior = p;
        p = p->next;
        index++;
    }

    if(prior == nullptr){
        ListNode *newHead = p->next;
        free(p);
        return newHead;
    }
    
    prior->next = p->next;
    free(p);
    return head;
}

int main(){
    return 0;
}