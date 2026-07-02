class Solution {
  public:
    int lcs(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<int> dp(m+1,0);

        dp[0]=0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
            
                if(str1[i-1]==str2[j-1]) dp[j]=1+dp[j-1];

                else dp[j]=max(dp[j],dp[j-1]);
                
            }
        }


        return dp[m];

    }
};
