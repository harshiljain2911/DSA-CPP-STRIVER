class Solution {
public:
    bool wildCard(string str, string pat) {
        int n = str.size();
        int m = pat.size();

        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);

        prev[0] = 1;

        for (int k = 1; k <= m; k++) {
            if (p[k - 1] == '*')
                prev[k] = prev[k - 1];
        }

        for (int i = 1; i <= n; i++) {

            fill(curr.begin(), curr.end(), 0);   // Reset current row
            curr[0] = 0;                         // Empty pattern can't match

            for (int j = 1; j <= m; j++) {

                if (str[i - 1] == pat[j - 1] || pat[j - 1] == '?') {
                    curr[j] = prev[j - 1];
                }
                else if (pat[j - 1] == '*') {
                    curr[j] = curr[j - 1] || prev[j];
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};
