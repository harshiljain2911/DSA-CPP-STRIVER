class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int l = 0;
        int maxlen = 0;
        int t = 0;

        for (int r = 0; r < nums.size(); r++) {

            if (nums[r] == 0) {
                t++;
            }

            while (t > k) {   // <-- FIX: use while instead of if
                if (nums[l] == 0) {
                    t--;
                }
                l++;   // always move left
            }

            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};
