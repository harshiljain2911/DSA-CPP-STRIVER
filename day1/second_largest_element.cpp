class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        
        int maxi = -1;
        int secmax = -1;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > maxi)
            {
                secmax = maxi;
                maxi = nums[i];
            }
            else if(nums[i] > secmax && nums[i] != maxi)
            {
                secmax = nums[i];
            }
        }

        return secmax;
    }
};
