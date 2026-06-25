class Solution {
public:
    int minDifference(vector<int>& arr, int n) {

        int sum = accumulate(arr.begin(), arr.end(), 0);

        vector<bool> prev(sum + 1, false);
        vector<bool> curr(sum + 1, false);

        // Base Cases
        prev[0] = true;

        if (arr[0] <= sum)
            prev[arr[0]] = true;

        // Fill DP
        for (int i = 1; i < n; i++) {

            curr[0] = true;

            for (int target = 1; target <= sum; target++) {

                bool skip = prev[target];

                bool take = false;

                if (arr[i] <= target)
                    take = prev[target - arr[i]];

                curr[target] = skip || take;
            }

            prev = curr;
        }

        int mini = INT_MAX;

        for (int s1 = 0; s1 <= sum; s1++) {

            if (prev[s1]) {

                int s2 = sum - s1;

                mini = min(mini, abs(s1 - s2));
            }
        }

        return mini;
    }
};
