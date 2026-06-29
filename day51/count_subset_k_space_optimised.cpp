class Solution {
public:
    int perfectSum(vector<int>& arr, int K) {

        const int MOD = 1e9 + 7;

        vector<int> dp(K + 1, 0);
        dp[0] = 1;

        for (int num : arr) {
            for (int t = K; t >= num; t--) {
                dp[t] = (dp[t] + dp[t - num]) % MOD;
            }
        }

        return dp[K];
    }
};
