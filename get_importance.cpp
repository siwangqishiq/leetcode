
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Employee{
public:
    int id;
    int importance;
    vector<int> subordinates;
};

int findImportanceValue(Employee *employee , vector<Employee*> &employees , 
    unordered_map<int , Employee* > &employeeMap,
    unordered_map<int , int> &cache){
    const int id = employee->id;
    if(cache.find(id) != cache.end()){
        return cache[id];
    }

    int result = employee->importance;
    vector<int> &subs = employee->subordinates;
    for(int idx : subs){
        Employee *subEmployee = employeeMap[idx];
        result += findImportanceValue(subEmployee, employees , employeeMap , cache);
    }//end for each
    cache[id] = result;
    return result;
}

int getImportance(vector<Employee*> employees, int id) {
    unordered_map<int , Employee*> employeeMap;
    for(Employee* employee: employees){
        employeeMap[employee->id] = employee;
    }//end for each

    unordered_map<int , int> cache;
    return findImportanceValue(employeeMap[id] , employees , employeeMap, cache);
}

int main(){
    return 0;
}

