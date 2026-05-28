class Solution {
public:
    bool canJump(vector<int>& nums) {

        int maxIndex = 0;

        for(int i = 0; i < nums.size(); i++) {

            // unreachable index
            if(i > maxIndex) //kya current position unreachable hai?
                return false;

            // update farthest reach
            maxIndex = max(maxIndex, i + nums[i]);
        }

        return true;
    }
};
