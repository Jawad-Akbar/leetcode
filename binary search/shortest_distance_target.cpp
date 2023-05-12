class Solution {
public:
    int dp[4][2][100000];
    vector<int> shortestDistanceColor(vector<int> colors, vector<vector<int>>& queries){
        int n=colors.size();

        dp[1][0][0]=-1;
        dp[2][0][0]=-1;
        dp[3][0][0]=-1;


        dp[1][0][n]=-1;
        dp[2][0][n]=-1;
        dp[3][0][n]=-1;
        int a;
        bool s1=false,s2=false,s3=false;
        for (int i=0;i<colors.size();i++){

            if (colors[i]==1)
                s1=1;
            if (colors[i]==2)
                s2=1;
            
            if (colors[i]==3)
                s3=1;
            
            //###########   first   ##############	
            a=-1;
            if (colors[i]==1)
                a=0;
            else if (s1)
                a=dp[1][0][i]+1;
            dp[1][0][i+1]=a;

            //###########   second   ##############	
            a=-1;
            if (colors[i]==2)
                a=0;
            else if (s2)
                a=dp[2][0][i]+1;
            dp[2][0][i+1]=a;


            //###########   third   ##############	
            a=-1;
            if (colors[i]==3)
                a=0;
            else if (s3)
                a=dp[3][0][i]+1;
            dp[3][0][i+1]=a;
        }
        s1=false,s2=false,s3=false;
        for (int i=colors.size()-1;i>-1;i--){
            if (colors[i]==1)
                s1=1;
            if (colors[i]==2)
                s2=1;
            
            if (colors[i]==3)
                s3=1;
            
            //###########   first   ##############	
            a=-1;
            if (colors[i]==1)
                a=0;
            else if (s1)
                a=dp[1][1][i+1]+1;
            dp[1][1][i]=a;

            //###########   second   ##############	
            a=-1;
            if (colors[i]==2)
                a=0;
            else if (s2)
                a=dp[2][1][i+1]+1;
            dp[2][1][i]=a;


            //###########   third   ##############	
            a=-1;
            if (colors[i]==3)
                a=0;
            else if (s3)
                a=dp[3][1][i+1]+1;
            dp[3][1][i]=a;
        }
        // cout<<"dp[1][0][i]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        // for (int i=1;i<=n;i++)
        // 	cout<<dp[1][0][i]<<" ";
        // cout<<endl;
        // cout<<"dp[2][0][i]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        // for (int i=1;i<=n;i++)
        // 	cout<<dp[2][0][i]<<" ";
        // cout<<endl;
        // cout<<"dp[3][0][i]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        // for (int i=0;i<=n;i++)
        // 	cout<<dp[3][1][i]<<" ";
        // cout<<endl;


        vector<int>ans;
        for (int q=0;q<queries.size();q++){
            int ind=queries[q][0];
            int tar=queries[q][1];

            int a=dp[tar][0][ind+1];
            int b=dp[tar][1][ind];

            if (a==-1 and b==-1)
                ans.push_back(-1);
            else if (a==-1 or b==-1)
                ans.push_back(a+b+1);
            else
                ans.push_back(min(a,b));
        }
        return ans;
    }
};