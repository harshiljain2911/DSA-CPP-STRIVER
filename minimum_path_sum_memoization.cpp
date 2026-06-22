class Solution {
public:
    int fun(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid) {

        if (i < 0 || j < 0)
            return INT_MAX;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (i == 0 && j == 0)
            return dp[i][j] = grid[0][0];

        int up = fun(i - 1, j, dp, grid);
        int left = fun(i, j - 1, dp, grid);

        return dp[i][j] = grid[i][j] + min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return fun(m - 1, n - 1, dp, grid);
    }
};
