class Solution {
public:
    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2){
        vector<int>v ;
        int n=nums1.size();
        int m=nums2.size();
        int nm=n+m;
        nums1.push_back(10000000);
        nums2.push_back(nums1.back());
        int i=0,j=0;
        while (nm--){
            if (nums1[i]<nums2[j])
                v.push_back(nums1[i++]);
            else
                v.push_back(nums2[j++]);
        }
        nm=n+m;
        if (nm%2==0)
            return (double)(v[nm/2-1]+v[nm/2])/2;
        else
            return (double)v[nm/2];
        return 2.5;
    }
};