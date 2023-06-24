class Solution {
public:
    int b;
    set<int> v;
    vector<int> p;
    int t=0;
    Solution(int n, vector<int>& a) {
        b=n;
        for (int i:a)
            v.insert(i);
        for (int i=0;i<=min(n-1,100001);i++)
            if (v.find(i)==v.end())
                p.push_back(i);
    }
    int pick() {
        for (int i=1;i<=20;i++){
            int k=rand()%b;
            if (v.find(k)==v.end())
                return k;
        }
        t++;
        return p[t%(p.size())];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */