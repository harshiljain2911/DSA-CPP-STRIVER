class Solution {
public:

    int maxProfit(vector<int>& prices) {

        long long profit = 0;

        int n = prices.size();

        vector<int> prev(2, 0);
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    profit = max(-prices[i] + curr[0], curr[1]);
                } else {
                    profit = max(prices[i] + next[1], curr[0]);
                }

                prev[buy] = profit;
            }

            next = curr;
            curr = prev;
        }

        return prev[1];

    }
};
