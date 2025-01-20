
#include <iostream>
#include <vector>

using namespace std;

long long nextStep(vector<int>& energyDrinkA, vector<int>& energyDrinkB, int &index,
    long long &result , bool &isA){
    const int size = energyDrinkA.size();
    if(index >= size){
        return result;
    }

    if(energyDrinkA[index] > energyDrinkB[index]){
        isA = true;
        result += energyDrinkA[0];
    }else if(energyDrinkA[0] < energyDrinkB[0]){
        isA = false;
        result += energyDrinkB[0];
    }else{
        index++;
        while(energyDrinkA[index] == energyDrinkB[index] && index < size){
            result += energyDrinkA[index];
            index++;
        }//end while
        if(index < size){

        }
    }
}

long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
    long long result = 0;
    
    const int size = energyDrinkA.size();
    
    int index = 0;
    bool isA = true;
    if(energyDrinkA[0] > energyDrinkB[0]){
        isA = true;
        result += energyDrinkA[0];
    }else if(energyDrinkA[0] < energyDrinkB[0]){
        isA = false;
        result += energyDrinkB[0];
    }else{
        index++;
        while(energyDrinkA[index] == energyDrinkB[index] && index < size){
            result += energyDrinkA[index];
            index++;
        }//end while
        if(index < size){

        }
    }
    
    
    while(index < size){
        if(isA){
            if(index + 1 >= size){//is last
                result += energyDrinkA[index];
                index++;
            }else{
                if(energyDrinkA[index] >= energyDrinkB[index + 1]){
                    result += energyDrinkA[index];
                    index++;
                }else{
                    result += energyDrinkB[index + 1];
                    isA = false;
                    index += 2;
                }
            }
        }else{ //in B
            if(index + 1 >= size){//is last
                result += energyDrinkB[index];
                index++;
            }else{
                if(energyDrinkB[index] >= energyDrinkA[index + 1]){
                    result += energyDrinkB[index];
                    index++;
                }else{
                    result += energyDrinkA[index + 1];
                    isA = true;
                    index += 2;
                }
            }
        }//end if
    }//end while
    return result;
}

int main(){
    // vector<int> a = {4,1,1};
    // vector<int> b = {1,1,3};

    vector<int> a = {1,3,1};
    vector<int> b = {3,1,1};
    cout << "result : " << maxEnergyBoost(a, b) << endl;
    return 0;
}

