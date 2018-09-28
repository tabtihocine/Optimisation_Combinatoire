#include <iostream>
#include "ugraph.h"
#include <vector>
#include<stack>



using namespace std;


UndirectedGraph::UndirectedGraph(int num_nodes){

this->adj2 = vector<vector<int>>(num_nodes);
}

void UndirectedGraph::AddEdge(int a, int b) {

    this-> adj2[a].push_back(b);
    this-> adj2[b].push_back(a);
    this-> nombre += 1;
}

int UndirectedGraph::NumNodes() const {

return this->adj2.size();
}


int UndirectedGraph::NumEdges() const {

    return  this->nombre;

}

int UndirectedGraph::Degree(int node) const {
    return adj2[node].size();

}

const vector<int> &UndirectedGraph::Neighbors(int node) const {
    return this->adj2[node];
}

//Inspiré de l'algorithme de BFS (Breadth-First Search)
vector<int> UndirectedGraph::GetNodesConnectedTo(int node) {
    vector <int> connected;
    vector <bool> visited;

    //Marquer tous les noeuds comme "non visité"
for(int i=0;i<this->adj2.size();i++){
    visited.push_back (false);
}
connected.push_back(node);
visited[node]=true;

while(!this->adj2.empty()){

    int front = connected.front();
    connected.pop_back();

    for(auto i= this->adj2[front].begin();i!=this->adj2[front].end();i++){
        if(!visited[*i]){
            connected.push_back(*i);
            visited[*i]=true;
        }
    }
}

    return connected;
}

/*vector<vector<int>> UndirectedGraph::ConnectedComponents() {


    return pile;
}
*/