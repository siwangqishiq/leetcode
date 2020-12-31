/**
 * 给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。
示例 1：

输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
示例 2：

输入：lists = []
输出：[]
示例 3：

输入：lists = [[]]
输出：[]
 

提示：

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] 按 升序 排列
lists[i].length 的总和不超过 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
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

ListNode* mergeKLists(vector<ListNode*>& lists){
    ListNode *p = nullptr;
    ListNode *head = nullptr;

    while(1){
        int index = -1;
        int minValue = 9999999;
        for(int i= 0 ; i < lists.size();i++){
            if(lists[i] != nullptr){
                if(minValue > lists[i]->val){
                    minValue = lists[i]->val;
                    index = i;
                }
            }
        }//end for i

        if(index >= 0){
            //cout << "inser data value = " << lists[index]->val << endl;
            if(p == nullptr){
                p = lists[index];
                head = p;
            }else{
                p->next = lists[index];
                p =p->next;
            }
            
            lists[index] = lists[index]->next; 
        }else{
            break;
        }
    }//end while 
 
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
    vector<int> l1 = {1,2,3};
    vector<int> l2 = {1,2,3,4};
    vector<int> l3 = {2,3,5,5};

    ListNode *list1 = buildNodeList(l1);
    ListNode *list2 = buildNodeList(l2);
    ListNode *list3 = buildNodeList(l3);

    vector<ListNode *> lists;
    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);

    ListNode *mergeList = mergeKLists(lists);
    printNode(mergeList);

    return 0;
}
