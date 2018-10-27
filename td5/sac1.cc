#include "sac1.h"
#include <algorithm>
using namespace std; 


int Sac1(int C, const vector<int>& p){
    vector<int> picked;
     vector<int> newP =p; 
    sort(newP.begin(), newP.end());
    int i= 0;
    int somme=0; 
    
  
    while ((somme<=C) && (i < newP.size())) {
        somme+=newP[i];
        picked.push_back(i);
        i++;
    }
    if(somme>C){
        return picked.size()-1;
    }
  
    
    return picked.size();
}