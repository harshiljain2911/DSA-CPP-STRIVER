class Solution {
public:
    bool equalpartition(int n,vector<int>& arr) {
        

        if ((accumulate(arr.begin(), arr.end(), 0) % 2 != 0))
            return false;
        else {

            int target = (accumulate(arr.begin(), arr.end(), 0)) / 2;

            vector<bool> dp(target + 1, false);

            dp[0] = true;
            if (arr[0] <= target)
                dp[arr[0]] = true;

            for (int i = 1; i < n; i++) {
                for (int j = target; j >= nums[i]; j--) {
                    dp[j] = dp[j] || dp[j - arr[i]];
                }
            }

            return dp[target];
        }
    }
};
