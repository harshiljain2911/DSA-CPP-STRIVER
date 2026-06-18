class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        if (n == 1) return 0;

        vector<int> dp(n, 0);          // dp[0] correctly initialized to 0
        dp[1] = abs(heights[1] - heights[0]);

        for (int i = 2; i < n; i++) {
            dp[i] = INT_MAX;            // start each dp[i] clean, not garbage
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {        // guards against negative index
                    dp[i] = min(dp[i], dp[i-j] + abs(heights[i] - heights[i-j]));
                }
            }
        }

        return dp[n-1];
    }
};
