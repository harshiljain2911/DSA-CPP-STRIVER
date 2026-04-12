class Solution{
  public:
    int longestNonRepeatingSubstring(string& s){
        vector<int> lastSeen(256, -1);
        int maxLen = 0;
        int left = 0;

        for(int right = 0; right < s.size(); right++) {
            char ch = s[right];

            // if character already seen
            if(lastSeen[ch] >= left) {
                left = lastSeen[ch] + 1;
            }

            lastSeen[ch] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
