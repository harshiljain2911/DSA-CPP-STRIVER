class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int cnt = 0;
       int maxi = 0;
       int right=0;
       for(right=0;right<nums.size();right++)
       {
            if(nums[right]==1)
            {
                cnt++;
                maxi = max(cnt,maxi);
            }
            else 
            {    
                cnt = 0;
            }
       } 
       return maxi;
    }
};
