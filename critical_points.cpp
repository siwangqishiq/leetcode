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

enum Types{
    Min,
    Max
};

struct CriticalPoint{
    int pos;
    Types type;
};

vector<int> buildCriticalPointVector(ListNode* head){
    ListNode* p = head;
    vector<int> list;
    while(p != nullptr){
        list.push_back(p->val);
        p = p->next;
    }//end while

    return list;
}

int findMaxDistance(vector<CriticalPoint> &list){
    if(list.size() < 2){
        return -1;
    }

    return list[list.size() - 1].pos - list[0].pos;
}

int findMinDistance(vector<CriticalPoint> &list, int maxDistance){
    if(list.size() < 2){
        return -1;
    }

    int minDistance = maxDistance;
    for(int i = 1; i < list.size() ; i++){
        int distance = list[i].pos - list[i - 1].pos;
        if(distance < minDistance){
            minDistance = distance;
        }
    }
    return minDistance;
}

vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    vector<int> result = {-1,-1};
    vector<int> list = buildCriticalPointVector(head);
    if(list.size() <= 3){
        return result;
    }
    
    //长度为3的卷积
    const int convSize = 3;
    vector<CriticalPoint> cirticalPointList;
    for(int i = 0; i < list.size() - convSize + 1; i++){
        // std::cout << " i = " << i << std::endl;
        // i + 0 , i + 1, i + 2
        if(list[i + 1] > list[i] && list[i + 1] > list[i + 2]){//极大值点
            cirticalPointList.push_back({i + 1, Max});
        }else if(list[i + 1] < list[i] && list[i + 1] < list[i + 2]){ //极小值点
            cirticalPointList.push_back({i + 1, Min});
        }
        // max
    }//end for i

    // for(auto &item : cirticalPointList){
    //     std::cout << item.pos << "  type : " << item.type << std::endl;
    // }

    int maxDistance = findMaxDistance(cirticalPointList);
    int minDistance = findMinDistance(cirticalPointList, maxDistance);

    result[0] = minDistance;
    result[1] = maxDistance;
    return result;    
}

ListNode* buildLinkedList(vector<int> &list){
    if(list.empty()){
        return nullptr;
    }

    ListNode *head = nullptr;
    ListNode *prior = nullptr;

    for(int i = 0; i < list.size() ; i++){
        ListNode *p = new ListNode(list[i]);
        if(prior != nullptr){
            prior->next = p;
        }else{
            head = p;
        }
        prior = p;
    }//end for i
    return head;
}

void printLinkedList(ListNode *head){
    auto p = head;
    while(p != nullptr){
        std::cout << p->val << "  ";
        p = p->next;
    }//end while
    std::cout << std::endl;
}

int main() {
    vector<int> list = {3,1};
    ListNode *p = buildLinkedList(list);
    // printLinkedList(p);

    auto result = nodesBetweenCriticalPoints(p);
    std::cout << result[0] << "  , " << result[1] << std::endl;
    return 0;
}