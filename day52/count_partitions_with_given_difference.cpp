#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    const int MOD = 1e9 + 7;

    int fun(int i, vector<int>& arr, int target, vector<vector<int>>& dp) {
        if (i == (int)arr.size() - 1) {
            if (arr[i] == 0) return target == 0 ? 2 : (target == arr[i]);
            return target == arr[i];
        }

        if (dp[i][target] != -1) return dp[i][target];

        int skip = fun(i + 1, arr, target, dp);
        int take = (target >= arr[i]) ? fun(i + 1, arr, target - arr[i], dp) : 0;

        return dp[i][target] = (skip + take) % MOD;
    }

    int countPartitions(int n, int diff, vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int tar = sum + diff;

        if (tar % 2 != 0 || sum < diff) return 0;

        vector<vector<int>> dp(n, vector<int>(tar / 2 + 1, -1));
        return fun(0, arr, tar / 2, dp);
    }
};
