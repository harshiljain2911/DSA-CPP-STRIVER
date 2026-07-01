class Solution {
public:
    int rodCutting(vector<int> price, int n) {

        vector<int> dp(n + 1, 0);
            for(int target=0; target<=n; target++)
            dp[0][target] = target * price[0];

        // Fill the DP table
        for (int ind = 1; ind < n; ind++) {

            int rodLength = ind + 1;

            for (int target = 0; target <= n; target++) {

                int notTake = dp[target];

                int take = INT_MIN;
                if (rodLength <= target) {
                    take = price[ind] + dp[target - rodLength];
                }

                dp[target] = max(take, notTake);
            }
        }

        return dp[n];
    }
};
