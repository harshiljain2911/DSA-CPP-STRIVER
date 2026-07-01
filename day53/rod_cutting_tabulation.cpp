class Solution {
public:
    int rodCutting(vector<int> price, int n) {

        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        // Base Case
        // Only rod of length 1 is available.
        for (int target = 0; target <= n; target++) {
            dp[0][target] = target * price[0];
        }

        // Fill the DP table
        for (int ind = 1; ind < n; ind++) {

            int rodLength = ind + 1;

            for (int target = 0; target <= n; target++) {

                int notTake = dp[ind - 1][target];

                int take = INT_MIN;
                if (rodLength <= target) {
                    take = price[ind] + dp[ind][target - rodLength];
                }

                dp[ind][target] = max(take, notTake);
            }
        }

        return dp[n - 1][n];
    }
};
