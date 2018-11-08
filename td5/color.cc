#include "color.h"
#include <algorithm>

using namespace std; 

int Color(const UndirectedGraph& graph,vector<int>* color){
  
    // calcul du dergré de chaque noeud 
    vector<int> dergry(graph.NumNodes());
    for(int i=0 ; i<graph.NumNodes() ; i++){
        dergry[i]= graph.Degree(i); 
    }


    //ordonner les degré dasn un ordre décroissant
    sort(dergry.begin() , dergry.end());
    reverse(dergry.begin() , dergry.end());
    int j=0;
    for (int i=0 ; i<dergry.size() ; i++){
      
       *color[i]=j;
        vector<int>voisin= graph.Neighbors(i);
        vector<int>::iterator it = find(voisin.begin(), voisin.end(), i+1);   
    }

    
}