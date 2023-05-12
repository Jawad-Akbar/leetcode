class Solution {
public:
    int n;
    bool seen[50][50];
    void dfs(int i,int j,int k,vector<vector<int>>& g){
        if (i<0 or i==n or j==n or j<0 or g[i][j]>k or seen[i][j])
            return;
        seen[i][j]=true;
        dfs(i-1,j,k,g);
        dfs(i+1,j,k,g);
        dfs(i,j-1,k,g);
        dfs(i,j+1,k,g);
    }
    bool valid(int k,vector<vector<int>>& g){
        dfs(0,0,k,g);
        bool t=seen[n-1][n-1];
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                seen[i][j]=false;
        return t;
    }
    int swimInWater(vector<vector<int>>& g) {
        n=g.size();
        // cout<<valid(16,g);

        // return 0;
        int l=0;
        int h=n*n-1;
        while (l<h){
            int mid=(l+h)/2;
            if (valid(mid,g))
                h=mid;
            else
                l=mid+1;
            cout<<mid<<endl;
        }
        return l;
    }
};