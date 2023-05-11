#include <iostream>
#include <cstdlib>

using namespace std;

float f(float x){
    // return -x*x + 3*x;
    return x*x;
}

float random(float a , float b){
    return a + static_cast<float>(rand()) / static_cast<float>(RAND_MAX/(b - a));
}

float monte_integrate(float x1 , float x2 , long iter_count){

    float total = 0.0f;
    for(int i = 0 ; i < iter_count;i++){
        float x = random(x1 , x2);
        float y = f(x) * (x2 - x1);
        total += (y);
    }

    return total / iter_count;
}

int main(){
    for(long i = 10 ;i < 1000000000;i= i * 2){
        auto result = monte_integrate(0.0f , 1.0f , i);
        cout << "iter count : " << i << " \t result = " << result << endl;
    }
    return 0;
}
