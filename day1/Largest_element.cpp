class Solution {
public:
    int largestElement(vector<int>& nums) {
        int maxi = 0;
        for(int i=0;i<nums.size();i++)
        {
            maxi = max(maxi,nums[i]); 
        }
    return maxi;

    }
};
