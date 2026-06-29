class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<unsigned long long> dp(amount + 1, 0);

        dp[0] = 1;

        for (int amt = 1; amt <= amount; amt++) {
            if (amt % coins[0] == 0)
                dp[amt] = 1;
            else
                dp[amt] = 0;
        }

        for (int i = 1; i < n; i++) {
            for (int amt = 1; amt <= amount; amt++) {
                if (amt >= coins[i])
                    dp[amt] = dp[amt] + dp[amt - coins[i]];
            }
        }

        return dp[amount];
    }
};
