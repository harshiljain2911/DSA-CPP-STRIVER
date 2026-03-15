class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {

        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.end()-k, nums.end());

    }
};
