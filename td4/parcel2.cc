#include "parcel2.h"
#include <algorithm>

using namespace std; 

vector<int> OptimalParcels(const vector<int>& gain){
 vector<int> parcel; 
if (gain.empty()){
parcel.clear();
return parcel;
} 


vector<int> maxGain(gain.size(), -1);
maxGain[0]= gain[0]; 
maxGain[1]= max(gain[0],gain[1]);

for(int i=2 ; i< gain.size() ; i++){
    maxGain[i]= max(gain[i]+ maxGain[i-2], maxGain[i-1]);   
}

int k = maxGain.size()-1; 
 while(k>=0){
     if(maxGain[k]>maxGain[k-1] ){
         parcel.push_back(k);
         k-=2;
     }else{   
         k--;
     }
 }
reverse(parcel.begin(),parcel.end());

return parcel;
}