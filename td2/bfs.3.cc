#include "bfs.3.h"
#include <vector>
#include <iostream>
using namespace std;

vector<int> GetShortestPathFromRootedTree(const vector<int>& parent, int target){

  vector<int> shortPath;
  int posIni=0;

  for(int i=0 ; i< parent.size(); i++){

   if (parent[target]==-1){
    return shortPath;
   }

   if(parent[target]==i){
    shortPath.push_back(i);
   }
  else{

       posIni= i;
       shortPath.push_back(target);
       i=parent[target];
        while(parent[i]!=i){
        i=parent[i];
        shortPath.push_back(i);
//

    }// end while
i=posIni;
  }// end else
   }//end for
   return shortPath;
}
