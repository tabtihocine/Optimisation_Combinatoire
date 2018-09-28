#include "bfs.1.h"
#include <vector>
#include<iostream>
#include <algorithm>
#include "ugraph.h"

using namespace std;

vector<int> BFS(const UndirectedGraph& graph, int src){

 vector <int> parent(graph.NumNodes(),-1);
 vector<int> file;
 file.push_back(src);
 parent[src]=src;

  while(!file.empty()){
    int noeud = file.front();
    file.erase(file.begin());
     for(int i : graph.Neighbors(noeud)){
     if(graph.GetNodesConnectedTo(noeud).empty()){
     parent[i]=-1;
     }
        if (parent[i]==-1){
               file.push_back(i);
               parent[i]=noeud;
           }
         }
      }
  return parent;
}
