#include "diam2.h"

using namespace std ; 

vector<int> DiametreUB(const UndirectedGraph& graph){
    vector<int> clic;
    clock_t Tmax = clock()+ CLOCKS_PER_SEC * (0.04 + (graph.NumNodes()+graph.NumEdges())*0.000001);
    int nodeSource=rand() % graph.NumNodes(); 
    int nodeEloigner=0;
    
    
    while(clock()< Tmax){
        int distance=0;   
        int nodeTemp=0;
       vector<int> dis =GetBfsDistances(BFS(graph,nodeSource)); 
            for(int j=0 ; j<dis.size() ; j++){
                if(dis[j]>distance){
                distance=dis[j];
                nodeTemp=j;
                }
            }   
        nodeEloigner=nodeSource;
        nodeSource=nodeTemp;

       
}
     vector<int> path = GetShortestPathFromRootedTree(BFS(graph,nodeEloigner),  nodeSource);
        if(path.size()%2!=0){
            int s = path.size()-1;
            int sd= s/2; 
            clic.push_back(path[s-sd]); 
        }
        if(path.size()%2==0) {
            clic.push_back(path[(path.size()/2)-1]); 
            clic.push_back(path[path.size()/2]);
            

        }
return clic;     
}