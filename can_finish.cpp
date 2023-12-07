/**
 * @file can_finish.cpp
    https://leetcode.cn/problems/course-schedule/
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-06
 * 
 * @copyright Copyright (c) 2023
 * 
207. 课程表
你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 


 */


#include <iostream>
#include <vector>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    if(numCourses <= 1){
        return true;
    }

    const unsigned int size = numCourses;
    int graph[size][size];
    for(int i = 0 ; i < size ;i++){
        for(int j = 0 ; j < size ;j++){
            graph[i][j] = 0;
        }//end for j
    }//end for i

    for(auto &v : prerequisites){
        // v[1] -> v[0]
        graph[v[1]][v[0]] = 1;
    }//end for each;

    for(int i = 0 ; i < size;i++){
        for(int j = 0 ; j < size;j++){
            cout << graph[i][j] << " ";
        }//end for j
        cout << endl;
    }//end for i

    vector<int> elements(size);
    for(int i = 0 ; i < size;i++){
        elements[i] = i;
    }//end for i
    
    return false;        
}

int main(){
    vector<vector<int>> prerequisites = {{1,0},{0,1}};
    bool can = canFinish(2 , prerequisites);
    if(can){
        cout<< "true\n";
    }else{
        cout<< "false\n";
    }
    // cout << "can = " << can << endl;
    return 0;
}


