class Solution {
public:

    long long rabin_karp(string a,long long m){
        long long mod = 109692529417;
        long long d = 256;
        long long n=a.size();
        long long s=0;
        long long ss=0;
        long long h=1;
        set<long long> k;
        for (long long i=0;i<m;i++){
            if (i!=0)
                h = (d*h) % mod;
            s = (d*s + (a[i]-1+1)) % mod;
        }
        for (long long i=0;i<n-m+1;i++){
            if (k.find(s)!=k.end())
                return i;
            k.insert(s);
            long long fc = (h*a[i]) % mod;
            if (i<n+m)
                s = (d*(s-fc)+a[i+m]) % mod;
            if (s<0)
                s+=mod;
        }
        return -1;
    }
    string longestDupSubstring(string s) {
        long long l=0,r=s.size();

        while (l+1<r){
            long long m = (l+r)/2;
            if (rabin_karp(s,m)!=-1)
                l=m;
            else
                r=m;
        }
        if (rabin_karp(s,r)!=-1)
            l=r;
        long long k = rabin_karp(s,l);
        string ss;
        for (long long i=k;i<k+l;i++)
            ss+=s[i];
        return ss; 
    }
};