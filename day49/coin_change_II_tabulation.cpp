class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // Base Case 1
        for(int i = 0; i < n; i++)
            dp[i][0] = 1;

        // Base Case 2
        for(int amt = 0; amt <= amount; amt++)
        {
            if(amt % coins[n-1] == 0)
                dp[n-1][amt] = 1;
            else
                dp[n-1][amt] = 0;
        }

        // Fill remaining rows
        for(int i = n - 2; i >= 0; i--)
        {
            for(int amt = 1; amt <= amount; amt++)
            {
                int skip = dp[i+1][amt];

                int take = 0;
                if(coins[i] <= amt)
                    take = dp[i][amt - coins[i]];

                dp[i][amt] = skip + take;
            }
        }

        return dp[0][amount];
    }
};
