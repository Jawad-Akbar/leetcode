class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        for (int i=0;i<nums1.size();i++)
            v.push_back(nums1[i]-nums2[i]);
        
        sort(begin(v),end(v));

        long long ans=0;
        int j=0;
        for (int i:v){
            j++;
            if (i<=0)
                ans+=v.size()-(upper_bound(begin(v),end(v),abs(i))-begin(v));
            else
                ans+=v.size()-j;
        }
        return ans;
    }
};