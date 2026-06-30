class Solution
{
    public:

    int fun(vector<vector<int>>& dp,vector<int>& wt,vector<int>& val,int i,int w,int n) {

        if(i==n-1) return (w/wt[i])*val[i];

        if(dp[i][w]!=-1) return dp[i][w];

        int skip = fun(dp,wt,val,i+1,w,n);
        int take =(w>=wt[i]) ?  (val[i] + fun(dp,wt,val,i,w-wt[i],n)) : 0;

        return dp[i][w] = max(skip , take);

    }

    int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) 
        {
            vector<vector<int>> dp(n,vector<int>((W+1),-1));

            return fun(dp,wt,val,0,W,n);
        }
};
