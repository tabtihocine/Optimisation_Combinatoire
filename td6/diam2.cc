#include "diam2.h"

using namespace std ; 

vector<int> DiametreUB(const UndirectedGraph& graph){
    vector<int> clic;
    clock_t Tmax = clock()+ CLOCKS_PER_SEC * (0.025 + (graph.NumNodes()+graph.NumEdges())*0.000001);
    int nodeSource=rand() % graph.NumNodes(); 
    int nodeEloigner=0;
    vector<vector<int>> allPath;
    vector<int> center;
    while(clock()< Tmax){
        
        vector<int> dis =GetBfsDistances(BFS(graph,nodeSource));
        int distance=0; 
        int nodeTemp=0;

            for(int j=0 ; j<dis.size() ; j++){
                if(dis[j]>distance){
                distance=dis[j];
                nodeTemp=j;
                }
            }   
        nodeEloigner=nodeSource;
        nodeSource=nodeTemp;

        vector<int> path = GetShortestPathFromRootedTree(BFS(graph,nodeSource), nodeEloigner);
       
        if(path.size()%2!=0){
            int s = path.size()-1;
            int sd= s/2; 
            clic.push_back(path[s-sd]); 
        }
        else {
            int s=path.size()/2;
            int sd= s-1; 
            clic.push_back(path[s]); 
            clic.push_back(path[sd]);
        }
        nodeSource=rand() % graph.NumNodes();
        allPath.push_back(clic); 
}
    int size= 1000;
    for(int i=0; i<allPath.size(); i++){
        if(allPath[i].size()<size){
            size=allPath[i].size();
            center=allPath[i];
        }
        
    }

return center;     
}