class Solution {
public:
    bool valid(int mid,int n,int m,int k){
        int kk=0;
        for (int i=1;i<=n;i++)
            kk+=min(m,mid/i);
        return (kk>=k);
    }
    int findKthNumber(int n, int m, int k) {
        int l=1,h=m*n;

        while (l<h){
            int mid=(l+h)/2;
            if (valid(mid,n,m,k))
                h=mid;
            else
                l=mid+1;
        }
        return l;
    }
};