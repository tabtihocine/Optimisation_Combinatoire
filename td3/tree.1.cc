#include "tree.1.h"
#include <vector>
#include <iostream>
using namespace std ;


vector<vector<int>> ParentVectorToChildrenVector(const vector<int>& parent){

   vector<vector<int>> childrens(parent.size());
     for (int i=0 ; i<parent.size() ; i++){
        if(parent[i]==-1){
         i=i;
        }else{
        childrens[parent[i]].push_back(i);
        }//end else
     }//end for

    return childrens;
}// end méthode
