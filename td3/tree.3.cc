#include "tree.3.h"
using namespace std;

vector<int> AllHeights(const vector<vector<int>>& enfants){
      vector<int> hei;



}


void HeightRc(const vector<int>& enfants){
vector<int> height;
int hh;

    if(enfants.empty()){
    height.push_back(0);
    }else{

    int temp=0;
    for(int i=0; i<enfants.size();i++){
      temp= HeightRc(enfants);
      height.push_back(temp)
    }
    }
 }
