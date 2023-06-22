class Solution {
public:
    map<pair<int,int>,bool> seen;
    vector<vector<int>> v;
    int n,m;
    bool vld(int i,int j){
        if (i<0 or j<0 or i==n or j==m)
            return false;
        if (seen[{i,j}])
            return false;
        return true;
    }
    void dfs(int i,int j,int k){

        seen[{i,j}]=true;
        if (vld(i-1,j) and abs(v[i-1][j]-v[i][j])<=k)
            dfs(i-1,j,k);
        if (vld(i+1,j) and abs(v[i+1][j]-v[i][j])<=k)
            dfs(i+1,j,k);
        if (vld(i,j-1) and abs(v[i][j-1]-v[i][j])<=k)
            dfs(i,j-1,k);
        if (vld(i,j+1) and abs(v[i][j+1]-v[i][j])<=k)
            dfs(i,j+1,k);
    }

    bool valid(int k){
        dfs(0,0,k);
        return (seen[{n-1,m-1}]);
    }

    int minimumEffortPath(vector<vector<int>>& h) {
        int l=0,r=1e6+10;
        v=h;
        n=v.size();
        m=v[0].size();
        while(l+1<r){
            seen.clear();
            int k= (l+r)/2;
            if (valid(k))
                r=k;
            else
                l=k;
        }
        seen.clear();
        if (valid(l))
            r=l;
        return r;

    }
};