class Solution {
public:
    int fun(int i,int amt,vector<int>& coins,vector<vector<int>>& dp) {
        if(amt==0) return 1;
        if(i==0) return (amt%coins[0]==0) ? 1 : 0;

        if(dp[i][amt]!=-1) return dp[i][amt];

        int skip = fun(i-1,amt,coins,dp);
        int take = 0;
        if(coins[i]<=amt) take = fun(i,amt-coins[i],coins,dp);

        return dp[i][amt] = skip + take;
    }

    int change(int amount, vector<int>& coins) {

        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));

        return fun(coins.size()-1,amount,coins,dp);

    }
};
