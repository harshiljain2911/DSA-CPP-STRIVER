class Solution {
public:
    long long fun(int i,int buy,vector<int>& prices,int fee,vector<vector<int>>& dp){
        
        long long profit = 0;

        if(i==prices.size()) return 0;
    
        if(dp[i][buy]!=-1) return dp[i][buy];

        if(buy)
        {
            profit = max(-prices[i]-fee + fun(i+1,0,prices,fee,dp),fun(i+1,1,prices,fee,dp));
        }
        else
        {
            profit = max(prices[i] + fun(i+1,1,prices,fee,dp),fun(i+1,0,prices,fee,dp));
        }

        return dp[i][buy] = profit;
    
    }


    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();

        vector<vector<int>> dp(n,vector<int>(2,-1));

        return fun(0,1,prices,fee,dp);

    }
};
