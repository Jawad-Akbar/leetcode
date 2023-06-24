class Solution {
public:
    int dp[1005];
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        int l=n;
        for (int j=1;j<n-1;j++){
            for (int i=1;i<=n;i++)
                dp[i]=2e9;
            int mxl=0;
            for (int i=0;i<=j;i++){
                int k=upper_bound(dp,dp+n+1,nums[i]-1)-dp;
                dp[k]=nums[i];
                mxl=k;
            }
            int mxl2=0;
            for (int i=1;i<=n;i++)
                dp[i]=2e9;
            dp[0]=0;
            for (int i=n-1;i>=j;i--){
                int k=upper_bound(dp,dp+n+1,nums[i]-1)-dp;
                dp[k]=nums[i];
                mxl2=k;
            }
            int lis=mxl+mxl2-1;
            if (mxl>1 and mxl2>1)
                l=min(l,n-lis);
        }
        return l;
    }
};