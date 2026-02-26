#include <iostream>
#include <string>

using namespace std;

int stringToInt(std::string &str){
    int valueInt = 0;
    if(str.empty()){
        return valueInt;
    }

    for(int i = 0; i < str.length() ; i++){
        valueInt = valueInt << 1;
        if(str[i] == '1'){
            valueInt += 1;
        }//end if
    }//end for i
    return valueInt;
}

int numSteps2(string s){
    int value = stringToInt(s);
    int counter = 0;
    while(value != 1){
        if(value % 2 == 0){
            value = value / 2;
        }else{
            value = value + 1;
        }
        counter++;
    }//end while
    return counter;
}

std::string stringInc(std::string &s){
    if(s.empty()){
        return "1";
    }
    std::string str = s;
    int index = s.length() - 1;
    while(index >= 0){
        if(str[index] == '0'){
            str[index] = '1';
            break;
        }else{
            str[index] = '0';
        }
        index--;
    }
    if(index < 0){
        str = std::string("1") + str;
    }
    return str;
}

int numSteps(string s){
    int counter = 0;

    while(s != "1"){
        const int len = s.size();
        auto lastCh = s[len - 1];
        // cout << lastCh << endl;
        if(lastCh == '0'){
            s = s.substr(0, len - 1);
        }else if(lastCh == '1'){
            s = stringInc(s);
        }
        counter++;
    }
    return counter;
}

void test2(){
    string str = "1011";
    std::cout << stringInc(str) << std::endl;
}

void test1(){
    string str = "101";
    std::cout << stringToInt(str) << std::endl;
}

int main(){
    // string s = "1101";
    // string s = "10";
    string s = "1111011110000011100000110001011011110010111001010111110001";
    auto result = numSteps(s);
    std::cout << "result = " << result << std::endl;

    // test1();
    // test2();
    return 0;
}