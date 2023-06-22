class MajorityChecker {
public:
    // srand();
    vector<int> q[20005];
    bool seen[20005];
    vector<int>a;
    MajorityChecker(vector<int>& arr) {
        int j=0;
        for (int i:arr)
            q[i].push_back(j++);
        for (int i:arr)
            if (!seen[i]){
                seen[i]=true;
                sort(begin(q[i]),end(q[i]));
            }
        a=arr;
    }
    int query(int left, int right, int threshold) {
        int len=right-left+1;
        for (int i=1;i<=7;i++){
            int ind = left+(rand()%len);
            int i1=upper_bound(begin(q[a[ind]]),end(q[a[ind]]),right)-begin(q[a[ind]]);
            int i2=upper_bound(begin(q[a[ind]]),end(q[a[ind]]),left-1)-begin(q[a[ind]]);
            if (i1-i2>=threshold)
                return a[ind];
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */