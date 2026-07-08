class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        long long profit = 0;
        vector<vector<int>> prev(2, vector<int>(k + 1, 0));
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = k-1; cap >= 0; cap--) {
                    if (buy) 
                    {
                        profit = max(-prices[i] + prev[0][cap], prev[1][cap]);
                    } 
                    else 
                    {
                        profit = max(prices[i] + prev[1][cap+1] , prev[0][cap]);
                    }
                    curr[buy][cap] = profit;
                }
            }
            prev = curr;
        }

        return prev[1][0];
    }
};
