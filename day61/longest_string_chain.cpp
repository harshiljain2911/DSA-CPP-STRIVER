class Solution {
public:

        bool checkpossible(string& s, string& t) {
        if (t.length() - s.length() != 1)
            return false;

        int first = 0;
        int second = 0;

        while (first < s.length() && second < t.length()) {
            if (s[first] == t[second]) {
                first++;
            }
            second++;
        }

        return first == s.size();
    }

    int longestStringChain(vector<string>& words) {
           sort(words.begin(), words.end(),
             [](string& a, string& b) { return a.size() < b.size(); });

        int n = words.size();

        vector<int> dp(n, 1);
        int maxi = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (checkpossible(words[j], words[i]) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
                maxi = max(dp[i], maxi);
            }
        }

        return maxi;
    }
};
