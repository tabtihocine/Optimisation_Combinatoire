#include "tree.2.h"
#include <vector>
#include<iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int Height(const vector<vector<int>>& enfants, int node){

    int height=0;
    int tmp=0;

    if(enfants[node].empty()){
        return 0;
    }else{


    for(int i =0 ; i<enfants[node].size(); i++){
        tmp = max(Height(enfants,enfants[node][i]), tmp);
    }

    height=1 +tmp;
    }//end else

    return height;
}
