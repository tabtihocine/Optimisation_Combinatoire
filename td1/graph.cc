    #include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

DirectedGraph::DirectedGraph(int num_nodes){

    this->adj= vector<vector <int>> (num_nodes);
}

void DirectedGraph::AddArc(int from, int to){

	this-> adj[from].push_back(to);
        this->n+=1;

}

int DirectedGraph::NumNodes() const{

return  this-> adj.size();

}

int DirectedGraph::OutDegree(int node) const{

	return this->adj[node].size();
}



const vector<int>& DirectedGraph::Neighbors(int node) const {

	return this-> adj[node];

}

int DirectedGraph:: NumArcs() const {

   return this->n;
}

void DirectedGraph::MakeSimple() {


    for (int i=0; i<this->adj.size(); i++) {
     adj[i].erase(unique(adj[i].begin(), adj[i].end()),adj[i].end());
        for (int t=0; t< this->adj[i].size();t++) {
           if(i==this->adj[i][t])   
		this->adj[i].erase(this->adj[i].begin()+t);

        }
    }
}



//Destructeur
DirectedGraph::~DirectedGraph() {

}
//andre.schrottenloher@inria.fr



