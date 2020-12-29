
/**
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == nullptr && l2 == nullptr){
        return nullptr;
    }else if(l1 != nullptr && l2 == nullptr){
        return l1;
    }else if(l1 == nullptr && l2 != nullptr){
        return l2;
    }

    ListNode *head = nullptr;
    ListNode *p = nullptr;

    ListNode *left = l1;
    ListNode *right = l2;
    do{
        //cout << "left : " << left->val << "  right: " << right->val << endl;
        if(left->val < right->val){
            if(p == nullptr){
                p = left;
            }else{
                p->next = left;
                p=p->next;
            }
            
            left = left->next;
        }else {
            if(p == nullptr){
                p = right;
            }else{
                p->next = right;
                p=p->next;
            }
            right = right->next;
        }

        if(head == nullptr){
            head = p;
        }
    }while(left != nullptr && right != nullptr);
    
    if(left != nullptr){
      p->next = left;  
    }

    if(right != nullptr){
        p->next = right;
    }

    return head;
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
    vector<int> list1 = {1,2,4,6,10};
    vector<int> list2 = {1,3,4};

    ListNode *list = mergeTwoLists(buildNodeList(list1) , buildNodeList(list2));
    printNode(list);
    return 0;
}


