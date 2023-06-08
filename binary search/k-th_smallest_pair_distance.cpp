class Solution {
public:
    int asd(vector<int>& nums,int m){
        int ans=0;
        for (int i=0;i<nums.size();i++){
            int k=(upper_bound(begin(nums),end(nums),nums[i]+m)-begin(nums));
            ans+=(k-i-1);
        }
        return ans;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        
        int l=0,r=1e7+10;
        while (l<r){
            int m=(l+r)/2;
            int mm=asd(nums,m);
            if (mm>=k)
                r=m;
            else
                l=m+1;
        }
        return l;
    }
};