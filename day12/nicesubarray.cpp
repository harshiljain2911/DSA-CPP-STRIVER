class Solution {
public:
int atMost(vector<int>& nums, int k) {
        int left = 0;
        int oddcount = 0;
        int count = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] % 2 == 1)
                oddcount++;

            while (oddcount > k) {
                if (nums[left] % 2 == 1)
                    oddcount--;
                left++;
            }

            count += right - left + 1;
        }

        return count;
    }
    int numberOfOddSubarrays(vector<int>& nums, int k) {
     return atMost(nums, k) - atMost(nums, k - 1);   
    }
};
