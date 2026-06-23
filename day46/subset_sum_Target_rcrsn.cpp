bool solve(int idx, int target, vector<int>& arr) {
    if (target == 0) return true;           // found a valid subset
    if (idx == 0) return arr[0] == target;  // only one element left
    
    bool skip = solve(idx - 1, target, arr);
    bool take = false;
    if (arr[idx] <= target)
        take = solve(idx - 1, target - arr[idx], arr);
    
    return skip || take;
}

bool isSubsetSum(vector<int>& arr, int target) {
    int n = arr.size();
    return solve(n - 1, target, arr);
}
