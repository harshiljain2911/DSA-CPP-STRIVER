class Solution {
public:
    int fun(int i, vector<int>& nums, vector<vector<int>>& dp, int tar) {
        if (i == nums.size() - 1) {
            if (tar == 0 && nums[i] == 0)
                return 2;
            if (tar == 0 || nums[i] == tar)
                return 1;
            return 0;
        }

        if (dp[i][tar] != -1)
            return dp[i][tar];

        int skip = fun(i + 1, nums, dp, tar);
        int take = (tar >= nums[i]) ? fun(i + 1, nums, dp, tar - nums[i]) : 0;

        return dp[i][tar] = skip + take;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum < target || (sum - target) % 2 != 0)
            return 0;
        else {
            vector<vector<int>> dp(nums.size(),
                                   vector<int>((sum - target) / 2 + 1, -1));
            return fun(0, nums, dp, (sum - target) / 2);
        }
    }
};
