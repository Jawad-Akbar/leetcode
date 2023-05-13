class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int>v;
        for (auto j:mat)
            for (int i:j)
                v.push_back(i);
        sort(begin(v),end(v));
        return v[k-1];
    }
};