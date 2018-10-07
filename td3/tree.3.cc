#include "tree.3.h"
#include <vector>
#include <iostream>
#include <iterator>
#include<bits/stdc++.h> 
using namespace std;

int Rec(const vector<vector<int>>& enfants , vector<int>& height, int node){

  int tmp=0;
  int hau=0;

  if(enfants[node].empty()){
    height[node]=0;
  }// end if 
  else{
     for(int i=0 ; i < enfants[node].size() ; i++){
       if(height[enfants[node][i]]!= -1){
         tmp= max(height[enfants[node][i]], tmp);
         hau=tmp+1;
         height[node]=hau;
       }// end if
       else{
           tmp = max (Rec(enfants , height , enfants[node][i]), tmp);
           hau= tmp+1;
           height[node]=hau;
       }// end else
     }// end for 
  }// end else 
     return hau;
}// end HeightRc
  
vector<int> AllHeights(const vector<vector<int> >& enfants) {
   vector<int> height (enfants.size(), -1);
      for(int i=0 ; i < enfants.size() ; i++){
        Rec(enfants,height,i);
      }
  return height;
}