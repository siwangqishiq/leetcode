#include <iostream>
#include <memory>

using namespace std;

class MinStack {
public:
    MinStack() {
        data = allocate(initSize);
        index = -1;
    }
    
    void push(int val) {
        if(index + 1 >= capacity){
            expand();
        }

        index++;
        data[index] = val;
    }
    
    void pop() {
        index--;
    }
    
    int top() {
        if(index < 0){
            return 0;
        }
        return data[index];
    }
    
    int getMin() {
        int min = data[0];
        for(int i = 0 ; i<= index; i++){
            //cout << " data [" <<  i  << "] = " << data[i] << endl;
            if(data[i] < min){
                min = data[i];
            }
        }//end for i
        // cout << " ********************* "<< endl;
        return min;         
    }
private:
    int index = 0;
    int capacity = 0;

    shared_ptr<int []> data;

    int initSize = 64;

    shared_ptr<int []> allocate(const int size){
        capacity = size;
        
        cout << "expand to " << capacity << endl;
        auto result = make_shared<int []>(new int[size]);
        cout << "allocate success " << result << endl;
        return result;
    }

    void expand(){
        capacity = capacity <= 0? initSize:capacity;

        cout << "expand " << capacity << endl;

        shared_ptr<int []> originData = data;
        shared_ptr<int []> data = allocate(capacity << 1);

        cout << "index : " << index << " cap " << capacity <<endl;
        for(int i = 0 ; i<= index; i++){
            data[i] = originData[i];
        }//end for i         
    }
};


/**
 * 
 * "nStack","push","push","push","push","getMin","pop","getMin","pop","getMin","pop","getMin"]
[   [],       [2],  [0],   [3],   [0],    [],      [],   [],     [],    [],     [],    []]
 * 
 * */
int main(){
    MinStack stack;

    stack.push(2);
    stack.push(0);
    stack.push(3);
    stack.push(0);

    stack.getMin();
    stack.pop();
    stack.getMin();
    stack.pop();
    stack.getMin();

    for(int i = 0 ; i< 100000;i++){
        stack.push(i + 2222);
    }

    cout << stack.getMin() << endl;

    return 0;
}


