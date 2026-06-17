class Solution {
public:
    vector<int> primesInRange(vector<vector<int>>& queries) {
        vector<int> ans;

        for (auto q : queries) {
            int L = q[0];
            int R = q[1];

            int n = R + 1;
            vector<bool> isPrime(n, true);

            if (n > 0) isPrime[0] = false;
            if (n > 1) isPrime[1] = false;

            for (long long p = 2; p * p <= R; p++) {
                if (isPrime[p]) {
                    for (long long multiple = p * p; multiple <= R; multiple += p) {
                        isPrime[multiple] = false;
                    }
                }
            }

            int count = 0;
            for (int i = max(2, L); i <= R; i++) {
                if (isPrime[i]) count++;
            }

            ans.push_back(count);
        }

        return ans;
    }
};
