class Solution {
public:

    int fun(int i,int pi,vector<int>& nums,vector<vector<int>>& dp){
        
        if(i==nums.size()) return 0;

        if(dp[i][pi+1]!=-1) return dp[i][pi+1];

        int len = 0 + fun(i+1,pi,nums,dp);

        if(pi==-1 || nums[i]>nums[pi])
        {
          len = max(len,1+fun(i+1,i,nums,dp));  
        } 

        return dp[i][pi+1]=len;

    }

    int LIS(vector<int>& nums) {
      
        int n = nums.size();

        vector<vector<int>> dp(n,vector<int>(n+1,-1));

        return fun(0,-1,nums,dp);
    }    
};
