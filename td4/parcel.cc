#include "parcel.h"

using namespace std;

int MaxGain(const vector<int>& gain) {

if (gain.empty()) return 0;

vector<int> maxGain(gain.size(), -1);
maxGain[0]= gain[0]; 
maxGain[1]= max(gain[0],gain[1]);

for(int i=2 ; i< gain.size() ; i++){
    maxGain[i]= max(gain[i]+ maxGain[i-2], maxGain[i-1]);
    
}
return maxGain[gain.size()-1];
}
