	#include "bfs.2.h"
#include <vector>
#include <iostream>
using namespace std;

vector<int> GetBfsDistances(const vector<int>& parent){

    vector<int> distance;
    int dis=0;
    int posIni=0;

    for(int i =0 ; i<parent.size() ; i++){

   if (parent[i]==-1){

      while(parent[i]==-1 && i<parent.size()){
        distance.push_back(-1);
        i++;

        }
    }

      if (parent[i]==i){
       distance.push_back(0);

      }

     else{
        posIni= i;
        while(parent[i]!=i && parent[i]>=0){
        i=parent[i];
        dis+=1;
        }
        distance.push_back(dis);
        dis=0;
        i=posIni;

      }//end else
    }//end for
    if (distance.size()> parent.size()) distance.pop_back();

    return distance;

}//end methode
