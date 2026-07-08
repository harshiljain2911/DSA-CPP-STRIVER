class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        long long profit = 0;
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = k-1; cap >= 0; cap--) {
                    if (buy) 
                    {
                        profit = max(-prices[i] + dp[i + 1][0][cap] , dp[i + 1][1][cap]);
                    } 
                    else 
                    {
                        profit = max(prices[i] + dp[i+1][1][cap+1] , dp[i+1][0][cap]);
                    }
                    dp[i][buy][cap] = profit;
                }
            }
        }

        return dp[0][1][0];
    }
};
