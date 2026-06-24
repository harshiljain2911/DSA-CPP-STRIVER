class Solution {
public:
    bool fun(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {

        if (target == 0)
            return true;

        if (i == 0)
            return nums[0] == target;

        if (dp[i][target] != -1)
            return dp[i][target];

        bool skip = fun(i - 1, target, nums, dp);
        bool take = (nums[i] <= target) ? fun(i - 1, target - nums[i], nums, dp)
                                        : false;

        return dp[i][target] = skip || take;
    }

    bool canPartition(vector<int>& nums) {

        if ((accumulate(nums.begin(), nums.end(), 0) % 2 != 0))
            return false;
        else {

            int target = (accumulate(nums.begin(), nums.end(), 0)) / 2;

            vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

            return fun(nums.size() - 1, target, nums, dp);
        }
    }
};
