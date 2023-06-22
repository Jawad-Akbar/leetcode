class Solution {
public:
    int n,m;
    int mnx=200,mxx=-1,mny=200,mxy=-1;
    bool seen[105][105];
    void dfs(int x,int y,vector<vector<char>>& image){
        
        if (x<0 or y<0 or x==n or y==m)
            return;
        if (seen[x][y])
            return;
        if (image[x][y]=='0')
            return;
        seen[x][y]=true;
        mnx=min(mnx,x);
        mny=min(mny,y);
        mxx=max(mxx,x);
        mxy=max(mxy,y);
        dfs(x-1,y,image);
        dfs(x+1,y,image);
        dfs(x,y-1,image);
        dfs(x,y+1,image);
    }

    int minArea(vector<vector<char>>& image, int x, int y) {
        n=image.size();
        m=image[0].size();
        dfs(x,y,image);
        int l=mxx-mnx+1;
        int w=mxy-mny+1;
        return l*w;
    }
};