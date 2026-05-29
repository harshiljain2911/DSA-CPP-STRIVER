class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Calculate total hours needed at speed mid
            long long hours = 0;
            for (int pile : piles) {
                hours += (pile + mid - 1) / mid;  // ceil(pile / mid) --> ceil(a/b) = (a+b-1)/b
            }

            if (hours <= h) {
                right = mid;      // mid works, try smaller
            } else {
                left = mid + 1;   // mid too slow, try faster
            }
        }

        return left;
    }
};
