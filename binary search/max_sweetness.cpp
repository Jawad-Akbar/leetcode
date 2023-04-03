#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool is_true_for(vector<int> &sweetness,int a,int k){
    int b=0;
    int n=sweetness.size();
    for (int i=0;i<n;i++){
        b+=sweetness[i];
        if (b>=a){
            k--;
            b=0;
        }
    }
    if (k<0)
        return true;
    return false;
}
int maximizeSweetness(vector<int>& sweetness, int k) {
	// sort(sweetness.begin(), sweetness.end());
    int mns=0;
    int mxs=1e6;
    while (mns+1<mxs){
        int mds=mns+(mxs-mns)/2;
        if (is_true_for(sweetness,mds,k))
            mns=mds;
        else
            mxs=mds;
        // cout<<mns<< " "<<mxs<<endl; 
    }
    return mns;
}
signed  main(){
	vector<int>v={1,2,3,4,5,6,7,8,9};
	cout<<maximizeSweetness(v, 5);
}