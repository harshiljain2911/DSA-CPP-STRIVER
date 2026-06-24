bool isSubsetSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<bool> dp(target + 1, false);
    
    dp[0] = true;  // empty subset
    if (arr[0] <= target) dp[arr[0]] = true;
    
    for (int i = 1; i < n; i++) {
        for (int j = target; j >= arr[i]; j--) {  // RIGHT TO LEFT — critical!
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }
    
    return dp[target];
}
