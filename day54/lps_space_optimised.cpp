class Solution {
public:
    int longestPalindromeSubseq(string s) {

        int n = s.size();

        vector<int> dp(n, 1);

        for (int i = n - 2; i >= 0; i--) {

            int prev = 0;   // represents dp[i+1][j-1]

            for (int j = i + 1; j < n; j++) {

                int temp = dp[j];   // save dp[i+1][j]

                if (s[i] == s[j])
                    dp[j] = 2 + prev;
                else
                    dp[j] = max(dp[j], dp[j - 1]);

                prev = temp;
            }
        }

        return dp[n - 1];
    }
};
