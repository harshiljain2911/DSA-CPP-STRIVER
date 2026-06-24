bool isSubsetSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
    
    // Base case 1: sum = 0 is always possible
    for (int i = 0; i < n; i++) dp[i][0] = true;
    
    // Base case 2: first element
    if (arr[0] <= target) dp[0][arr[0]] = true;
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= target; j++) {
            bool skip = dp[i-1][j];
            bool take = (arr[i] <= j) ? dp[i-1][j - arr[i]] : false;
            dp[i][j] = skip || take;
        }
    }
    
    return dp[n-1][target];
}
