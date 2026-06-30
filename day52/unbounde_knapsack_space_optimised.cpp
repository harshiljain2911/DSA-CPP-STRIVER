class Solution
{
    public:

    int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) 
    {
        vector<int> dp((W+1),0);

        for(int t=0;t<=W;t++) dp[t] = (t/wt[n-1])*val[n-1];  

        for(int i=n-2;i>=0;i--)
        {
            for(int t = 0;t<=W;t++)
            {
                int skip = dp[t];
                int take =(t>=wt[i]) ?  (val[i] + dp[t-wt[i]]) : 0;

                dp[t] = max(skip , take);
            }
        }

        return dp[W];

    }
};
