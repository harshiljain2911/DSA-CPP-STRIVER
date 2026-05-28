class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0)
            return 0;

        sort(nums.begin(), nums.end());

        int lngth = 1;
        int curr = 1;

        for(int first = 1; first < nums.size(); first++) {

            // consecutive
            if(nums[first] - nums[first - 1] == 1) {

                curr++;
            }

            // duplicate
            else if(nums[first] == nums[first - 1]) {

                continue;
            }

            // sequence break
            else {

                curr = 1;
            }

            lngth = max(lngth, curr);
        }

        return lngth;
    }
};
