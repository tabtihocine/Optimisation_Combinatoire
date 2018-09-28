#include "vgraph.h"
#include <utility>

using  namespace std;

DirectedGraph::DirectedGraph(int num_nodes) : neighbors_(num_nodes), num_arcs_(0) {}

void DirectedGraph::AddArc(int from, int to, double length) {
    neighbors_[from].push_back(make_pair(to,length));
    ++num_arcs_;
}

int DirectedGraph::NumNodes() const {
    return neighbors_.size();
}

int DirectedGraph::NumArcs() const {
    return num_arcs_;
}

int DirectedGraph::OutDegree(int node) const {
    return neighbors_[node].size();
}

const vector<pair<int,double>>& DirectedGraph::Neighbors(int node) const {
    return neighbors_[node];
}

void DirectedGraph::MakeSimple() {
    vector<bool> visited(NumNodes(), false);
    for (int i = 0; i < NumNodes(); ++i) {
        vector<int>& adj = neighbors_[i];
        int kept = 0;
        for (int& x : adj) {
            if (x != i && !visited[x]) {
                visited[x] = true;
                adj[kept++] = x;
            }
        }
        adj.resize(kept);
        for (int x : adj) visited[x] = false;
    }
}
