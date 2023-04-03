int missingElement(vector<int>& nums, int k) {
    int mtn=0;// mtn is the number of missing till now elements;
    nums.push_back(int(1e9)+7);
    for (int i=1;i<nums.size();i++){
        int missing_here=nums[i]-nums[i-1]-1;
        if (mtn+missing_here>=k){
            k-=mtn;
            return nums[i-1]+k;
        }
        mtn+=missing_here;
    }
    return 0;
}