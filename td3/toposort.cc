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
        degre[i]+=graph.OutDegree(i);
        if (degre[i]==0){
            fifo.push_back(i);
            cout << fifo[i] << endl; 
        }
         
            for(int j = 0 ; j < graph.Neighbors(i).size() ; j++ ){
                parent[graph.Neighbors(i)[j]].push_back(i);
            
        }
        //cout << degre[i] << endl;
        
    }

       //int k=0;
     for (int i=0 ; i<graph.NumNodes() ; i++){
        triTopologique.push_back(fifo.front());
        fifo.erase(fifo.begin());
            for(int j=0 ; j<parent[i].size(); j++){
                degre[parent[i][j]]--;
                if(degre[parent[i][j]]==0){
                    fifo.push_back(i);
                }
            }
            
    }
    
//Tester si l'on  a un cycle
    if(fifo.empty()&&triTopologique.size()!=graph.NumNodes()){
        
        triTopologique.clear() ;
    }
    

    
   return triTopologique;
}
