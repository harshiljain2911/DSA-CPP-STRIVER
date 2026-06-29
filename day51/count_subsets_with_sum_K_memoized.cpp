class Solution{
	public:

    int mod = 1e9 + 7;

    int fun(int num,int target,vector<int>& arr,vector<vector<int>>& dp) {
        if(target==0) return 1;   
        if(target<0) return 0;  
        if(num==arr.size()-1) return arr[num]==target;                  

        if(dp[num][target]!=-1) return dp[num][target];

        int skip = fun(num+1,target,arr,dp);
        int take = 0;
        if(target>=arr[num]) take = fun(num+1,target-arr[num],arr,dp);

        return dp[num][target] = (skip + take)%mod;
    }

	int perfectSum(vector<int>&arr, int K){
        
        vector<vector<int>> dp(arr.size(),vector<int>(K+1,-1));

        return fun(0,K,arr,dp);
	}
};
