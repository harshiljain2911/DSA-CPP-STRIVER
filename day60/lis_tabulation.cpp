class Solution {
public:
    int LIS(vector<int>& nums) {
      
        int n = nums.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int i=n-1;i>=0;i--)
        {
            for(int pi=i-1;pi>=-1;pi--)
            {
                int len = dp[i+1][pi+1];

                if(pi==-1 || nums[i]>nums[pi])
                    {
                        len = max(len,1+dp[i+1][i+1]);  
                    } 

                dp[i][pi+1]=len;

            }
        }

        return dp[0][0];
    }    
};
