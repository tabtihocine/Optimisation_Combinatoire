
#include <iostream>
#include <vector>
#include "tree.4.h"
#include <algorithm>
#include <math.h>

using namespace std;

int compteur(const vector<vector<int> >& enfants,vector<int>& subtrees, int node){
    int temporaire =0;
    int  nombre=0;

    if(enfants[node].empty()){
        return 1;
    }else{

    for(int i=0;i<enfants[node].size();i++){
            temporaire+= compteur(enfants,subtrees,enfants[node][i]);
    }
    nombre+=temporaire+1;
    temporaire=0;
    }
    
    return nombre;

}


vector<int> AllSubtreeSizes(const vector<vector<int> > &enfants)
{
    vector<int> subtrees(enfants.size(), -1);
    for (int i = 0; i < enfants.size(); i++)
    {   
        subtrees[i]=compteur(enfants,subtrees,i);
   
    }
    return subtrees;
}