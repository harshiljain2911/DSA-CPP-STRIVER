class Solution {
  public:

    int fun(int i,int j,string & s1, string & s2,vector<vector<int>> & dp) {
        
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j]=1+fun(i-1,j-1,s1,s2,dp);

        else return dp[i][j]=max(fun(i-1,j,s1,s2,dp),fun(i,j-1,s1,s2,dp));
    
    }

    int lcs(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        return fun(n-1,m-1,str1,str2,dp);
    }
};
