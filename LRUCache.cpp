/**
 * 
 * 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
实现 LRUCache 类：

LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。
当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 

进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？

 

示例：

输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出
[null, null, null, 1, null, -1, null, -1, 3, 4]

解释
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4
 

提示：

1 <= capacity <= 3000
0 <= key <= 3000
0 <= value <= 104
最多调用 3 * 104 次 get 和 put

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lru-cache
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
*/

#include <iostream>
#include <list>
#include <unordered_map>
#include <memory>

using namespace std;

class Node{
public:
    int key;
    int value;

    Node(int _key , int _value){
        this->key = _key;
        this->value = _value;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        mCapacity = capacity >= 1?capacity: 1;
    }
    
    int get(int key) {
        if(mMap.find(key) == mMap.end()){//not find
            return -1;
        } else {
            shared_ptr<Node> node = mMap[key];
            mList.remove(node);
            mList.push_front(node);

            return node->value;
        }
    }
    
    void put(int key, int value) {
        shared_ptr<Node> pNode = make_shared<Node>(key , value);
        if(mMap.find(key) != mMap.end()){//need remove from list
            shared_ptr<Node> oldNode = mMap[key];
            mMap.erase(oldNode->key);
            mList.remove(oldNode);
        }
        innerInsert(key , pNode);
    }

    void showContent(){
        cout << "====== cache ======" << endl;
        for(shared_ptr<Node> pN : mList){
            cout << "\t" << pN->value << " = " << pN->value << endl;
        }//end for each
        cout << "====== cache end ====="<< endl;
    }
private:
    int mCapacity;
    list<shared_ptr<Node>>  mList;
    unordered_map<int , shared_ptr<Node>> mMap;

    void innerInsert(int key , shared_ptr<Node> pNode){
        //cout << "list size = " << mList.size() << " capacity = " << mCapacity << endl;
        while(mList.size() + 1 > mCapacity){
            shared_ptr<Node> lstNode =mList.back();
            mMap.erase(lstNode->key);
            mList.pop_back();
        }//end while

        mList.push_front(pNode);
        mMap[key] = pNode;
    }
};

int main(){
    LRUCache *cache = new LRUCache(2);
    cache->put(1,1);
    cache->put(2,2);
    cache->get(1);
    cache->put(3,3);

    cache->showContent();

    cache->get(2);
    cache->showContent();

    cache->put(4 ,4);
    cache->showContent();

    cout << "get(1) = " << cache->get(1) << endl;
    cout << "get(3) = " << cache->get(3) << endl;
    cout << "get(4) = " << cache->get(4) << endl;

    delete cache;
    return 0;
}