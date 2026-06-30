class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum < target || (sum - target) % 2 != 0)
            return 0;
        else {
            int tar = (sum - target) / 2;
            vector<int> dp(tar + 1, 0);

            int n = nums.size();

            if (nums[n - 1] == 0)
                dp[0] = 2;
            else
                dp[0] = 1;

            if (nums[n - 1] != 0 && nums[n - 1] <= tar)
                dp[nums[n - 1]] = 1;

            for (int i = nums.size() - 2; i >= 0; i--) {
                for (int t = tar; t >= 0; t--) {
                    int skip = dp[t];
                    int take = (t >= nums[i]) ? dp[t - nums[i]] : 0;
                    dp[t] = skip + take;
                }
            }

            return dp[tar];
        }
    }
};
