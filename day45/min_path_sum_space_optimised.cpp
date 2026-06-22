class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> dp(n);

        // First row initialization
        for(int j = 0; j < n; j++)
            dp[j] = matrix[0][j];

        for(int i = 1; i < m; i++) {

            vector<int> curr(n);

            for(int j = 0; j < n; j++) {

                int up = dp[j];

                int leftDiag = INT_MAX;
                if(j > 0)
                    leftDiag = dp[j - 1];

                int rightDiag = INT_MAX;
                if(j < n - 1)
                    rightDiag = dp[j + 1];

                curr[j] = matrix[i][j] +
                          min({up, leftDiag, rightDiag});
            }

            dp = curr;
        }

        return *min_element(dp.begin(), dp.end());
    }
};
