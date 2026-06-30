class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum < target || (sum - target) % 2 != 0)
            return 0;
        else {
            int tar = (sum - target) / 2;
            vector<vector<int>> dp(nums.size(), vector<int>(tar + 1, 0));

            int n = nums.size();

            if (nums[n - 1] == 0)
                dp[n - 1][0] = 2;
            else
                dp[n - 1][0] = 1;

            if (nums[n - 1] != 0 && nums[n - 1] <= tar)
                dp[n - 1][nums[n - 1]] = 1;


            for (int i = nums.size() - 2; i >= 0; i--) {
                for (int t = tar; t >= 0; t--) {
                    int skip = dp[i + 1][t];
                    int take = (t >= nums[i]) ? dp[i + 1][t - nums[i]] : 0;
                    dp[i][t] = skip + take;
                }
            }

            return dp[0][tar];
        }
    }
};
