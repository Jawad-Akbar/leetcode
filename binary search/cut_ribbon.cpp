#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool is_valid(vector<int> &v,int k,int a){
    int s=0;
    for (int i:v)
        s+=i/a;
    return (s>=k);
}
int maxLength(vector<int>& v, int k) {
    int min=0;
    int max=1e9+7;

    while (min+1<max){
        int mid=min+max;
        mid/=2;
        if (is_valid(v,k,mid))
            min=mid;
        else
            max=mid;
        // cout<<min<< " "<<max<<endl;
    }        
    return min;
}
signed  main(){
    vector<int>v={9,7,5};
    cout<<maxLength(v, 22);
}