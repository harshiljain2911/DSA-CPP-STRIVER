class Solution {
public:

    int fun(int i,int buy,int cap,int k,vector<int>& prices,vector<vector<vector<int>>>& dp){
        
        long long profit = 0;
        
        if(i==prices.size()) return 0;

        if(cap==k) return 0;

        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];

        if(buy)
        {
            profit = max(-prices[i]+fun(i+1,0,cap,k,prices,dp),fun(i+1,1,cap,k,prices,dp));
        }
        else
        {
            profit = max(prices[i]+fun(i+1,1,cap+1,k,prices,dp),fun(i+1,0,cap,k,prices,dp));
        }

        return dp[i][buy][cap]=profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2, vector<int>(k + 1, -1)));

        return fun(0,1,0,k,prices,dp);
    }
};
