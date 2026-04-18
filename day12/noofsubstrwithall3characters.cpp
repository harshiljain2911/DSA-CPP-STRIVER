class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int result = 0;
        vector<int> freq(3, 0);
        for (int r = 0; r < s.size(); r++) {
            freq[s[r] - 'a']++;

            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                // Count all substrings from current right to end
                result += (s.length() - r);

                // Decrease frequency of character at left and move left forward
                freq[s[l] - 'a']--;
                l++;
            }
        }
        return result;
    }
};
