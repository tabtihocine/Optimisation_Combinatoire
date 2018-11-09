#include "diam1.h"

using namespace std; 

pair<int,int> DiametreLB(const UndirectedGraph& graph){

     pair<int,int> pair ={0,0};
     vector<int> dis;
   
     clock_t Tmax = clock()+ CLOCKS_PER_SEC * (0.03 + (graph.NumNodes()+graph.NumEdges())*0.000001);
     int nodeSource=rand() % graph.NumNodes(); 
     int nodeEloigner=0;

    while(clock()< Tmax){
        
            dis =  GetBfsDistances(BFS(graph,nodeSource)); 
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
}

pair.first=nodeSource;
pair.second=nodeEloigner;

return pair;
}