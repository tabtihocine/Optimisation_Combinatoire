#include "bfs.2.h"
#include <vector>
#include <iostream>
using namespace std;

vector<int> GetBfsDistances(const vector<int>& parent){

    vector<int> distance;
    int dis=0;
int posIni=0;
    for(int i =0 ; i<parent.size() ; i++){
      if(parent[i]==-1){
        distance.push_back(-1);
      }//end if

      if (parent[i]==i){

       distance.push_back(0);
      }//end if

      else{
         posIni= i;
        while(parent[i]!=i){

            i=parent[i];
            dis+= 1;
         }//end while

        i= posIni;
        distance.push_back(dis);

      }//end else

    }//end for

    return distance;

}//end methode