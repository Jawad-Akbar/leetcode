class Solution {
public:
    
    long long pre[100005];
    long long asd(vector<int>& p, vector<vector<int>>& b){
        long long m=1e15+100;
        bool t=false;
        for (auto v:b){
            long long s=0;
            long long sum=0;
            for (long long i=0;i<v.size();i++){
                long long k=(upper_bound(begin(p),end(p),v[i])-begin(p));
                sum+=(k-s)*v[i];
                sum-=(pre[k]-pre[s]);
                s=k;
            }
            if (s==p.size()){
                m=min(m,sum);
                t=true;
            }
        }
        if (t)
            return m;
        return -1;
    }
    long long minWastedSpace(vector<int>& p, vector<vector<int>>& b){
        if (p.size()==0)
            return 0;
        for (long long i=0;i<b.size();i++)
            sort(begin(b[i]),end(b[i]));
        
        sort(begin(p),end(p));

        pre[0]=0;
        for (long long i=0;i<p.size();i++)
            pre[i+1]=pre[i]+p[i];
        if (asd(p,b)==-1)
            return -1;
        long long l=0,h=2e10+10;

        while (l<h){
            long long m=(l+h)/2;
            long long k=asd(p,b);
            if (k<=m)
                h=m;
            else
                l=m+1;
        }
        return (l%(1000000007));

    }
};