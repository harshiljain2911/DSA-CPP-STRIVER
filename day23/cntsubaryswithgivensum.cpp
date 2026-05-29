class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;   // empty subarray has sum 0

        int prefixSum = 0, count = 0;

        for (int num : nums) {
            prefixSum += num;

            // Check if (prefixSum - k) was seen before
            if (prefixCount.count(prefixSum - k)) {
                count += prefixCount[prefixSum - k];
            }

            prefixCount[prefixSum]++;
        }

        return count;
    }
};
