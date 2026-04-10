class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size() - 2;
        int mid;
        if (nums.size() == 1 || nums[0] != nums[1]) {
            return nums[0];
        } else if (nums[nums.size() - 2] != nums[nums.size() - 1]) {
            return nums[nums.size() - 1];
        } else {

            while (low <= high) {
                mid = (low + high) / 2;
                if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                    return nums[mid];
                } else if ((nums[mid] == nums[mid + 1] && mid % 2 == 0) ||
                           (nums[mid] == nums[mid - 1] && mid % 2 == 1)) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
