/***
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。


示例 1：


输入：head = [1,2,3,4]
输出：[2,1,4,3]
示例 2：

输入：head = []
输出：[]
示例 3：

输入：head = [1]
输出：[1]
 

提示：

链表中节点的数目在范围 [0, 100] 内
0 <= Node.val <= 100

 * 
 * */

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

ListNode* swapPairs(ListNode *head){
    vector<ListNode *> list;
    ListNode *p = head;

    while(p != nullptr){
        list.push_back(p);
        p = p->next;
    }

    for(int i = 0 ; i < list.size();i+=2){
        if(i + 1 < list.size()){
            ListNode *tmp = list[i];
            list[i] = list[i + 1];
            list[i + 1] = tmp;
        }
    }//end for i

    for(int i = 0 ; i <  list.size() ; i++){
        if(i + 1 < list.size()){
            list[i]->next = list[i + 1];
        }else{
            list[i]->next = nullptr;
        }
    }//end for i

    return list.empty()? head : list[0];
}

ListNode* buildNodeList(vector<int> &data){
    ListNode *head = nullptr;

    ListNode *prior = nullptr;
    for(int i = 0 ; i < data.size();i++){
        ListNode *node = new ListNode(data[i]);
        if(prior != nullptr){
            prior->next = node;
        }
        prior = node;

        if(i == 0){
            head = node;
        }
    }//end for i

    return head;
}

void printNode(ListNode *head){
    ListNode *p = head;

    while(p != nullptr){
        cout << p->val ;

        if(p->next != nullptr){
            cout << "->";
        }
        p = p->next;
    }//end while
    cout << endl;
}


int main(){
    vector<int> list = {1,2};
    ListNode *li = buildNodeList(list);
    
    printNode(swapPairs(li));
    return 0;
}



