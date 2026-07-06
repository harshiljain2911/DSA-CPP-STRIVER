class Solution {
public:

    int fun(int i,int j,string& s,string& t,vector<vector<int>>& dp){
        
        if(i<0) return j+1;
        if(j<0) return i+1;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]) return dp[i][j] = fun(i-1,j-1,s,t,dp);

        return dp[i][j] = 1 + min(fun(i-1,j-1,s,t,dp),min(fun(i,j-1,s,t,dp),fun(i-1,j,s,t,dp)));
                            //        replace                 insert              delete
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        return fun(n-1,m-1,word1,word2,dp);
    }
};
