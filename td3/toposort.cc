#include "toposort.h"
#include <vector> 
#include <queue>
#include <iostream>
using namespace std; 

vector<int> TopologicalSort(const DirectedGraph& graph){
    
    vector<int> triTopologique; 
    vector<vector<int>> parent(graph.NumNodes()); 
    vector<int> degre(graph.NumNodes());
    vector<int> fifo; 

    for(int i =0 ; i < graph.NumNodes() ; i++ ){

        if (graph.Neighbors(i).empty()){
            fifo.push_back(i);
        }else{
            for(int j = 0 ; j < graph.Neighbors(i).size() ; j++ ){
                parent[graph.Neighbors(i)[j]].push_back(graph.Neighbors(i)[j]);
            }
        }
       int k=0;
       while(!fifo.empty()) {
           triTopologique.push_back(fifo[k]);
            for(int j=0 ; j <parent[i].size(); j++){
                degre[parent[i][j]]-=1;
                if(degre[parent[i][j]]==0){
                    fifo.push_back(parent[i][j]);
                }
            }
       }
    

    
   return triTopologique;
}