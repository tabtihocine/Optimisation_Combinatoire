#include "sac2.h"
#include <iostream>
#include <algorithm>
using namespace std; 

struct Obejct{
    int poid ;
    double valeur; 
};

bool compar(Obejct o1 , Obejct o2){
     if(o2.poid==0)
        return false;
     if(o1.poid==0)
         return true;     
     if((o1.valeur/o1.poid)>(o2.valeur/o2.poid)){
         return true; 
     }
 return false;
     
}


double Sac2(int C, const vector<int>& p, const vector<double>& v){


vector<Obejct> obejct;
for(int i=0 ; i<p.size(); i++){
    obejct.push_back({p[i],v[i]});
}

sort(obejct.begin(), obejct.end(), compar);

int i=0 ; 
int somme=0; 
double value=0; 
vector<int> picked; 
vector<double> iValue; 

    while((somme<=C) && (i < obejct.size())){
   
     somme+=obejct[i].poid;
     picked.push_back(obejct[i].poid);
     iValue.push_back(obejct[i].valeur); 
     value+=iValue[i];
     i++;

    }

    if(somme>C){
    int enTrop = somme -C ; 
    int Prendre = picked.back()- enTrop ;
    double newValue= (Prendre*iValue.back())/picked.back();
    value-=iValue.back();
    value+=newValue; 
     } 
    

    return value;
}