class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        stack<int> s1,s2;
        for (int i=0;i<k;i++)
            s1.push(nums[i]);
        for (int i=nums.size()-1;i>k;i--)
            s2.push(nums[i]);
        
        int ans=nums[k];
        int mn=nums[k];
        int l=1;
        while (s2.size()>0 or s1.size()>0){
            int now;
            if (s2.size()==0 or (!s1.empty() and s1.top()>=s2.top())){
                now=s1.top();
                s1.pop();
            }
            else if (s1.size()==0 or (!s2.empty() and s2.top()>=s1.top())){
                now=s2.top();
                s2.pop();
            }
            mn=min(mn,now);
            l++;
            ans=max(ans,l*mn);
        }
        return ans;
    }
};