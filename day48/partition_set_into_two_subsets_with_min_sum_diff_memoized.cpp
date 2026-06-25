class Solution{
  public:
    bool fun(int i,int target,vector<vector<int>>& dp,vector<int>& nums) {
        
        if(target==0) return dp[i][target] = true;
        if(i==0) return dp[i][target]  = (nums[0]==target);
        if(dp[i][target]!=-1) return dp[i][target];

        bool skip = fun(i-1,target,dp,nums);
        bool take = false;
        if(nums[i]<=target) take = fun(i-1,target-nums[i],dp,nums);

        return dp[i][target] = skip||take;

    }


	int minDifference(vector<int>&arr, int n)  { 
        
        int sum = accumulate(arr.begin(),arr.end(),0);
        
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        for (int i = 0; i <= sum; i++) 
        {
            bool dummy = fun(n - 1, i, dp, arr);
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
