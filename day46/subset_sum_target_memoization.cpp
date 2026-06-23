class Solution{   
public:
    bool solve(int i,int target,vector<int>& arr,vector<vector<int>>& dp) {
        if(target==0) return true;

        if(i==0) return arr[0]==target;

        if(dp[i][target]!=-1) return dp[i][target];



        bool skip = solve(i-1,target,arr,dp);
        bool take = false;
        if(arr[i]<=target) take = solve(i-1,target-arr[i],arr,dp);

        return dp[i][target] = take||skip;
    }


    bool isSubsetSum(vector<int>& arr, int target){
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,arr,dp);   
    }
};
