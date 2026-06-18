class Solution {
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        if (n == 1) return 0;

        vector<int> dp(n, 0);
        dp[1] = abs(heights[1] - heights[0]);

        for (int i = 2; i < n; i++) {
            int oneStep = dp[i-1] + abs(heights[i] - heights[i-1]);
            int twoStep = dp[i-2] + abs(heights[i] - heights[i-2]);
            dp[i] = min(oneStep, twoStep);
        }

        return dp[n-1];
    }
};
