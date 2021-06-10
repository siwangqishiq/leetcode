/**
 * 
 * 
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

进阶：

你可以设计一个只使用常数额外空间的算法来解决此问题吗？
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 

示例 1：


输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]
示例 2：


输入：head = [1,2,3,4,5], k = 3
输出：[3,2,1,4,5]
示例 3：

输入：head = [1,2,3,4,5], k = 1
输出：[1,2,3,4,5]
示例 4：

输入：head = [1], k = 1
输出：[1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 * */

#include <iostream>
#include <vector>
#include <list>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(list<ListNode *> &list , int reverseSize , ListNode* &tail){
    if(list.size() < reverseSize){
        tail = list.back();
        return list.front();
    }

    ListNode *head = nullptr;
    ListNode *pre = nullptr;

    while(!list.empty()){
        if(head == nullptr){
            head = list.back();
            list.pop_back();
            head->next = nullptr;

            pre = head;
        }else{
            ListNode *curNode = list.back();
            list.pop_back();
            curNode->next = nullptr;

            //cout << "cur = " << curNode->val << endl;
            pre->next = curNode;
            pre = curNode;
        }
    }//end while

    tail = pre;

    return head;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *p = head;
    ListNode *newHead = nullptr;
    ListNode *preTail = nullptr;
    list<ListNode *> containerList;

    int index = 0;
    while(p != nullptr){
        if(index < k){
            containerList.push_back(p);
            index++;
            p = p->next;
        }else if(index == k){
            ListNode *tail = nullptr;
            ListNode *subHead = reverseList(containerList , k , tail);

            // cout << "subHead = " << subHead->val << "   tail = " << tail->val << endl;

            if(newHead == nullptr){
                newHead = subHead;
            }

            if(preTail != nullptr){
                preTail->next = subHead;
            }

            preTail = tail;
            index = 0;
        }
    }//end while

    ListNode *tail = nullptr;
    ListNode *subHead = reverseList(containerList , k , tail);
    if(newHead == nullptr){
        newHead = subHead;
    }
    if(preTail != nullptr){
        preTail->next = subHead;
    }

    
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
    ListNode *head = new ListNode(1);
    ListNode *pre = head;

    // list<ListNode *> list;
    // list.push_back(head);

    // for(int i = 2 ; i <= 5;i++){
    //     ListNode *node = new ListNode(i);
    //     pre->next = node;
    //     pre = node;

    //     // list.push_back(node);
    // }

    // head = reverseList(list,100);

    head = reverseKGroup(head , 1);

    printList(head);

    return 0;
}