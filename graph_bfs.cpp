#include <iostream>
#include <vector>
#include <map>
#include <deque>

using namespace std;

void printGraph(map<int, vector<int>> &graph) {
    for(auto &p : graph) {
        std::cout << p.first <<"  [";
        
        for(auto &v : p.second){
            std::cout << v << " ";
        }
        std::cout << "]" << std::endl;
    }
}

using GraphType = map<int, vector<int>>;

GraphType buildGraph(const int size, vector<vector<int>> &pres) {
    GraphType graph;
    
    for(auto &p : pres) {
        //p[1] -> p[0]
        const int from = p[1];
        const int to = p[0];
        
        vector<int>& nextList = graph[from];
        nextList.push_back(to);
    }//end for each

    return graph;
}

bool visitGraphNoLoop(GraphType &graph, int startNode) {
    deque<int> tasks;
    tasks.push_back(startNode);

    map<int,bool> visitNodes;

    while(!tasks.empty()) {
        const int node = tasks.front();
        tasks.pop_front();

        // cout << "start:" << startNode << "   check node:" << node << std::endl;

        if(visitNodes.find(node) != visitNodes.end()){
            continue;
        }

        visitNodes[node] = true;
        if(graph.find(node) != graph.end()){
            vector<int> &nexts = graph[node];
            for(int i = 0 ; i < nexts.size() ; i++){
                tasks.push_back(nexts[i]);
            }//end for i
        }
    }//end while

    return true;
}


bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    const int size = numCourses;
    auto graph = buildGraph(numCourses, prerequisites);
    
    // printGraph(graph);    
    for(int i = 0 ; i < numCourses ; i++){
        if(!visitGraphNoLoop(graph, i)) {
            std::cout << "false node = " << i << std::endl;
            return false;
        }
    }//end 
    return true;        
}

int main() {
    int numCourses = 5;
    // vector<vector<int>> pres = {{2,0},{1,0},{3,1},{3,2},{1,3}};
    vector<vector<int>> pres = {{1,4},{2,4},{3,1},{3,2}};
    auto result = canFinish(numCourses, pres);
    if(result) {
        std::cout << "result = true" << std::endl;
    }else{
        std::cout << "result = false" << std::endl;
    }
    return 0;
}
