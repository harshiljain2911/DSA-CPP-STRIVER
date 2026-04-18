class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int l = 0;
        int maxfreq = 0;
        int maxlen = 0;

        for (int r = 0; r < s.size(); r++) {
            m[s[r]]++;
            maxfreq = max(maxfreq, m[s[r]]);

            while ((r - l + 1) - maxfreq > k) {
                m[s[l]]--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};
