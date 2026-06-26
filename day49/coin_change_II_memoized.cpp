class Solution {
public:
    int fun(int idx, int amt, vector<int>& coins,
            vector<vector<int>>& dp)
    {
        if (amt == 0)
            return 1;

        if (idx == coins.size())
            return 0;

        if (dp[idx][amt] != -1)
            return dp[idx][amt];

        int notTake = fun(idx + 1, amt, coins, dp);

        int take = 0;

        if (coins[idx] <= amt)
            take = fun(idx, amt - coins[idx], coins, dp);

        return dp[idx][amt] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {

        vector<vector<int>> dp(coins.size(),
                               vector<int>(amount + 1, -1));

        return fun(0, amount, coins, dp);
    }
};
