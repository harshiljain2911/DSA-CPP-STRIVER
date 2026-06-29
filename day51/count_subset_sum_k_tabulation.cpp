class Solution{
	public:
	int perfectSum(vector<int>&arr, int K){
        int n = arr.size();

        vector<vector<int>> dp(n,vector<int>(K+1,0));

        for(int i=0;i<n;i++) dp[i][0] = 1;

        for(int t = 1;t<=K;t++) if(arr[0] <= K) dp[0][arr[0]] = 1;
        
        for(int i=1;i<n;i++)
        {
            for(int t=1;t<=K;t++)
            {
                int skip = dp[i-1][t];
                int take = 0;
                if(t>=arr[i]) take = dp[i-1][t-arr[i]];

                dp[i][t] = (skip + take)%(1e9+7);
            }
        }

        return dp[n-1][K];

	}
};
