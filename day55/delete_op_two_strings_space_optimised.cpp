class Solution {
public:

    int lcs(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        vector<int> dp(m + 1, 0);

        for (int i = 1; i <= n; i++) {

            int prevDiagonal = 0;

            for (int j = 1; j <= m; j++) {

                int temp = dp[j];

                if (str1[i - 1] == str2[j - 1])
                    dp[j] = 1 + prevDiagonal;
                else
                    dp[j] = max(dp[j], dp[j - 1]);

                prevDiagonal = temp;
            }
        }

        return dp[m];
    }

    int minDistance(string word1, string word2) {

        int len = lcs(word1, word2);

        return word1.length() + word2.length() - 2 * len;
    }
};
