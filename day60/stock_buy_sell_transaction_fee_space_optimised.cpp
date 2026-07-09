class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        long long profit = 0;

        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    profit = max(-prices[i] - fee + next[0], next[1]);
                } else {
                    profit = max(prices[i] + next[1], next[0]);
                }
                curr[buy]=profit;
            }
            next = curr;
        }

        return curr[1];
    }
};
