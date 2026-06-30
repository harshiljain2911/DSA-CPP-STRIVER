class Solution
{
    public:

    int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) 
        {
            vector<vector<int>> dp(n,vector<int>((W+1),0));

        for(int t=0;t<=W;t++) dp[n-1][t] = (t/wt[n-1])*val[n-1];  

        for(int i=n-2;i>=0;i--)
        {
            for(int t = 0;t<=W;t++)
            {
                int skip = dp[i+1][t];
                int take =(t>=wt[i]) ?  (val[i] + dp[i][t-wt[i]]) : 0;

                dp[i][t] = max(skip , take);
            }
        }

        return dp[0][W];

        }
};
