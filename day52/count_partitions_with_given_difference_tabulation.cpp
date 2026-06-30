#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    const int MOD = 1e9 + 7;

    int fun(vector<int>& arr, int target, vector<vector<int>>& dp) {

        for(int i=0;i<arr.size();i++) dp[i][0] = 1;

        for (int t = 0; t <= target; t++) {
            if (arr[n-1] == 0)
                dp[n-1][t] = (t == 0) ? 2 : (t == arr[n-1] ? 1 : 0);
            else
                dp[n-1][t] = (t == arr[n-1]) ? 1 : 0;
        }
        

        for(int k=n-2;k>=0;k--)
        {
            for(int j=0;j<=target;j++)
            {
                int skip = dp[i+1][target];
                int take = (target >= arr[i]) ? dp[i+1][target-arr[i]] : 0;
                dp[i][j] = (skip + take) % MOD;
            }
        }

        

        return dp[0][target];
    }

    int countPartitions(int n, int diff, vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int tar = sum + diff;

        if (tar % 2 != 0 || sum < diff) return 0;

        vector<vector<int>> dp(n, vector<int>(tar / 2 + 1, 0));
        return fun(arr, tar / 2, dp);
    }
};
