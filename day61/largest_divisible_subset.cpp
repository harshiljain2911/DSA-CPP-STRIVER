class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        // DP array to store length of LIS ending at each index
        vector<int> dp(n, 1);

        // Array to store previous index of LIS element for reconstruction
        vector<int> prev(n, -1);

        // Compute LIS length for each index
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    // Update dp[i] and store previous index
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }

        // Find the index of maximum LIS length
        int maxLen = 0, maxIndex = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxIndex = i;
            }
        }

        // Reconstruct LIS sequence
        vector<int> lisSeq;
        int curr = maxIndex;
        while (curr != -1) {
            lisSeq.push_back(nums[curr]);
            curr = prev[curr];
        }

        return lisSeq;
    }
};
