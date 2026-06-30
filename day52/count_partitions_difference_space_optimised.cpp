#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    const int MOD = 1e9 + 7;
    int countPartitions(int n, int diff, vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int tar = sum + diff;

        if (tar % 2 != 0 || sum < diff) return 0;

        vector<int> dp(tar / 2 + 1, 0);

        for (int t = 0; t <= tar/2; t++) {
            if (arr[n-1] == 0)
                dp[t] = (t == 0) ? 2 : (t == arr[n-1] ? 1 : 0);
            else
                dp[t] = (t == arr[n-1]) ? 1 : 0;
        }

        for(int k=n-2;k>=0;k--)
        {
            for(int j=tar/2;j>=0;j--) // right to left, critical
            {
                int skip = dp[j];
                int take = (tar/2 >= arr[k]) ? dp[tar/2-arr[k]] : 0;
                dp[j] = (skip + take) % MOD;
            }
        }
        return dp[tar/2];
    }
};
