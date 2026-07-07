class Solution {
public:
    long long fun(int i, int buy, int cap, vector<int>& prices,
                  vector<vector<vector<int>>>& dp) {

        long long profit = 0;

        if (cap == 2)
            return 0;

        if (i == prices.size())
            return 0;

        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];

        if (buy) {
            profit = max(-prices[i] + fun(i + 1, 0, cap, prices, dp),
                         fun(i + 1, 1, cap, prices, dp));
        } else {
            profit = max(prices[i] + fun(i + 1, 1, cap + 1, prices, dp),
                         fun(i + 1, 0, cap, prices, dp));
        }

        return dp[i][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1)));

        return fun(0, 1, 0, prices, dp);
    }
};
