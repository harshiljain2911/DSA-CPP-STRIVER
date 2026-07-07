class Solution {
public:
    bool fun(int i, int j, vector<vector<int>>& dp, string &s, string &p) {

        // Both strings exhausted
        if (i < 0 && j < 0)
            return true;

        // Pattern exhausted but string remains
        if (j < 0)
            return false;

        // String exhausted but pattern remains
        if (i < 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }

        // Memoization
        if (dp[i][j] != -1)
            return dp[i][j];

        // Characters match or '?'
        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j] = fun(i - 1, j - 1, dp, s, p);

        // '*'
        if (p[j] == '*')
            return dp[i][j] = (fun(i, j - 1, dp, s, p) ||
                               fun(i - 1, j, dp, s, p));

        // Characters don't match
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return fun(n - 1, m - 1, dp, s, p);
    }
};
