class SummaryRanges {
public:
    set<int>s;
    // int start[10005],end[10005];
    // bool seen[10008];
    // map<pair<int,int>,int> intvals;
    SummaryRanges() {
        
    }
    
    void addNum(int n) {
        // if (seen[n])
        //     return;
        // seen[n]=true;
        // if (i!=0 and seen[n-1] and seen[n+1]){
        //     intvals.erase({start[n-1],n-1});
        //     intvals.erase({n+1,end[n+1]});
        //     intvals[{start[n-1],end[n+1]}]=1;
        // }
        // else if (i!=0 and seen[n-1]){
        //     intvals.erase({start[n-1],n-1});
        //     intvals[{strat[n-1],n}]=1;
        //     start[n]=start[n-1];
        //     end[n]=n;
        // }
        // else if (seen[n+1]){
        //     intvals.erase({n+1,end[n+1]});
        //     intvals[{n,end[n+1]}]=1;
        //     start[n]=n;
        //     end[n]=end[n+1];
        // }
        // else
        // {
        //     intvals[{n,n}]=1;
        //     end[n]=n;
        //     start[n]=n;
        // }
        s.insert(n);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        // for (auto i:intvals->first)
        //     ans.push_back({i.first,i.second});
        // return ans;
        int st=-1,e=-1; 
        for (int i:s){
            if (st==-1)
                st=i,e=i;
            else if (i-e>1){
                ans.push_back({st,e});
                st=i,e=i;
            }
            else
                e=i;
        }
        if (st!=-1)
            ans.push_back({st,e});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */









