#include <iostream>
#include <vector>

using namespace std;

class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        mDataVec.push_back(val);
        if(val < minValue){
            minValue = val;
        }
    }
    
    void pop() {
        if(mDataVec.empty()){
            return;
        }

        if(mDataVec.size() == 1){
            minValue = 2147483647;
            mDataVec.erase(mDataVec.end() - 1);
            return;
        }

        int topValue = mDataVec[mDataVec.size() - 1];
        if(minValue == topValue){
            minValue = mDataVec[0];
            for(int i = 1 ; i < mDataVec.size() - 1; i++){
                if(mDataVec[i] < minValue){
                    minValue = mDataVec[i];
                }
            }//end for i
        }
        
        mDataVec.erase(mDataVec.end() - 1);
    }
    
    int top() {
        if(mDataVec.empty()){
            return 0;
        }

        return mDataVec[mDataVec.size() - 1];
    }
    
    int getMin() {
        return minValue;
    }
private :
    vector<int> mDataVec;
    int minValue = 2147483647;
};

int main(){
    MinStack *stack = new MinStack();
    stack->push(1);
    stack->push(2);
    cout << "top : " << stack->top() << endl;
    cout << "getMin : " << stack->getMin() << endl;
    delete stack;

    return 0;
}
