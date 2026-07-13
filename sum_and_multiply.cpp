#include <iostream>
#include <vector>

using namespace std;

vector<int> parseNumber(int n) {
    vector<int> result;

    if(n <= 0) {
        return result;
    }

    int num = n;
    while(num != 0) {
        int weight = num % 10;
        num = num / 10;
        if(weight != 0) {
            result.push_back(weight);
        }
    } //end while
    return result; 
}

long long sumAndMultiply(int n) {
    auto weights = parseNumber(n);
    long long result = 0;
    long long sum = 0;
    long long x = 0;

    const int size = weights.size();

    for(int i = size - 1; i >= 0; i--){
        int value = weights[i];
        
        x = 10 * x + value;
        sum += value;
    }// end for i
    return sum * x;        
}


int main() {
    auto weights = parseNumber(1000);
    for(int i : weights) {
        std::cout << i << std::endl;
    }//end for i

    auto result = sumAndMultiply(1000);
    std::cout << "result = " << result << std::endl;
    return 0;
}
