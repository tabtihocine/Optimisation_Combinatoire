#ifndef DIRECTEDGRAPH_H_
#define DIRECTEDGRAPH_H_

#include <vector>
#include <algorithm>

using namespace std;

class DirectedGraph {

 public:
  // At construction, the graph has no arcs.
   DirectedGraph(int num_nodes);


  int NumNodes() const;

  // Count number of edges in a directed graphe
  int NumArcs() const;

  void AddArc(int from, int to);

  // Returns the number of arcs originating from "node".
  // In the example above, OutDegree(1) = 3, OutDegree(4) = 0.
  int OutDegree(int node) const;

  // Returns all the destination nodes that were added with arcs
  // originating from "node".
  // In the example above, Neighbors(1) is {0, 2, 3} and Neighbors(2) is {0}.
  const vector<int>& Neighbors(int node) const;

  //remove loops and multiarcs : make it simple
 void MakeSimple();

  virtual ~DirectedGraph();

 private:

 vector <vector<int>> adj;
 int n=0 ;
};
#endif
