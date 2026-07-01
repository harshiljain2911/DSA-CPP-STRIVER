class Solution {
public:
    int fun(int ind, int target, vector<int>& price, vector<vector<int>>& dp) {

        // Base Case
        if (ind == 0) {
            return target * price[0];
        }

        if (dp[ind][target] != -1)
            return dp[ind][target];

        // Don't take current rod length
        int notTake = fun(ind - 1, target, price, dp);

        // Take current rod length (Unbounded)
        int take = INT_MIN;
        int rodLength = ind + 1;

        if (rodLength <= target)
            take = price[ind] + fun(ind, target - rodLength, price, dp);

        return dp[ind][target] = max(take, notTake);
    }

    int rodCutting(vector<int> price, int n) {

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return fun(n - 1, n, price, dp);
    }
};
