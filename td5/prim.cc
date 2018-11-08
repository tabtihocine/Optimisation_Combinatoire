#include "prim.h"
#include   <iostream>
using namespace std;

//Comparer les poids de deux aretes et prendre le minimum
struct compare{
   bool  operator () (const Edge& p1, const Edge& p2) 
    { 
        return p1.weight>p2.weight; 
    } 
};

int Prim(int N, const vector<Edge>& edges){

    int minEdge=0;
    Edge picked;
    vector<bool> visited (N, false);
    priority_queue < Edge, vector<Edge> , compare > fileP;
    vector<vector<int>> adj(N);

    for (int i = 0 ; i<edges.size(); i++){
        adj[edges[i].node1].push_back(edges[i].node2);
        adj[edges[i].node2].push_back(edges[i].node1);
    }

    fileP.push(edges[0]);
    visited[edges[0].node1]=true;
    

    while(!fileP.empty()){
        picked= fileP.top();
        fileP.pop();

        if(visited[picked.node2]==true){
          continue;

        }else{
            minEdge+=picked.weight;
        
            for(int i=0;i<adj[picked.node1].size();i++ )
            {
                fileP.push(edges[adj[picked.node1][i]]);
                
            }
        visited[picked.node2]=true;
  
        }

    }
    return minEdge;
}