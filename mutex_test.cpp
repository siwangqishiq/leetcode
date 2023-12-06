
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

class SafeStack{
public:
    void push(int value){
        std::lock_guard guard(mutex);
        data.push_back(value);
    }

    int pop(){
        int ret = data.at(0);
        data.pop_back();
        std::lock_guard guard(mutex);
        return ret;
    }
private:
    std::mutex mutex;
    std::vector<int> data;
};

int main(){
    return 0;
}




