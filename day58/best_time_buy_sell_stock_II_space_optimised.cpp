class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        long long profit=0;

        vector<int> dp(2, 0);
        

        for (int i = n-1; i >=0; i--) {
            for (int j = 0; j <= 1; j++) {
                if (j) {
                    profit = max(-prices[i] + dp[0],
                                 dp[1]);
                } else {
                    profit = max(prices[i] + dp[1],
                                 dp[0]);
                }

                dp[j] = profit;
            }
        }

        return dp[1];
    }
};
