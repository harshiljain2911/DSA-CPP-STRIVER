class Solution{
  public:
    bool fun(int target,vector<vector<bool>>& dp,vector<int>& nums) {
        
        if(target==0) for(int k=0;k<nums.size();k++) dp[k][0] = true;
        if(nums[0]<=target) dp[0][nums[0]] = true;

        for(int i=1;i<nums.size();i++)
        {
            for(int j=1;j<target;j++)
            {
                bool skip = dp[i-1][j];
                bool take = (nums[i]<=j) ? dp[i-1][j-nums[i]] : false ;

                dp[i][j] = skip||take;
            }
        }

        return dp[nums.size()-1][target];

    }


	int minDifference(vector<int>&arr, int n)  { 
        
        int sum = accumulate(arr.begin(),arr.end(),0);
        
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        for (int i = 0; i <= sum; i++) 
        {
            bool dummy = fun(i, dp, arr);
        }

        int mini = 1e9;

        for (int i = 0; i <= sum; i++) 
        {
            if (dp[n - 1][i] == true) 
            {
                int diff = abs(i - (sum - i));
                mini = min(mini, diff);
            }
        }
    return mini;
	} 
};
