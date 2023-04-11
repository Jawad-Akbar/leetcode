class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        set<pair<long double ,pair<int,int>>>s;
        for (int i=0;i<arr.size();i++)
            for (int j=i+1;j<arr.size();j++)
                s.insert({(long double)arr[i]/arr[j],{arr[i],arr[j]}});
        int j=0;
        vector<int>v;
        for (auto i:s){
            j++;
            if (j==k){
                v={i.second.first,i.second.second};
                break;
            }
        }
        return v;
    }
};












