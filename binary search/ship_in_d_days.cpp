#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool is_valid(int a, vector<int>&v,int d){
    int w=0;
    for(int i=0;i<v.size();i++){
        w+=v[i];
        if(v[i]>a)
            return false;
        if(w>a){
            w=v[i];
            d--;
        }
    }
    return(d>0);
}

int shipWithinDays(vector<int>& v, int d) {
    int mn=0;
    int mx=1e9+7;
    while(mx>mn){
        int mid=(mn+mx)/2;
        if(is_valid(mid,v,d)){mx=mid;}
        else{mn=mid+1;}
    }
    return mn;
}
signed  main(){
    vector<int>v={1,2,3,4,5,6,7,8,9,10};
    cout<<shipWithinDays(v, 5);
}