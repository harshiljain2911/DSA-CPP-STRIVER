class Solution {
public:
    int fun(int m, int n, vector<vector<int>>& dp, vector<vector<int>>& grid) {

        dp[0][0] = grid[0][0];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int up = INT_MAX;
                int left = INT_MAX;
                if (i == 0 && j == 0)
                    continue;
                if (i > 0)
                    up = dp[i-1][j];
                if (j > 0)
                    left = dp[i][j-1];

                dp[i][j] = grid[i][j] + min(up, left);
            }
        }

        return dp[m - 1][n - 1];
    }

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        return fun(m, n, dp, grid);
    }
};
