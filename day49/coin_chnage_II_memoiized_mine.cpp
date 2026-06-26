class Solution {
public:
    int fun(int i,int amt,vector<vector<int>>& dp,vector<int>&coins) {
        if(amt==0) return 1;
        if(i==coins.size()-1) return ((coins[i]<=amt)&&(amt%coins[i]==0))? 1 : 0;

        if(dp[i][amt]!=-1) return dp[i][amt];
        int skip = fun(i+1,amt,dp,coins);
        int take = 0;
        if(coins[i]<=amt) take = fun(i,amt-coins[i],dp,coins);

        return dp[i][amt] = skip + take;

    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        return fun(0,amount,dp,coins);
    }
};
