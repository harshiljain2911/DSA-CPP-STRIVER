class Solution {
public:
    int fun(vector<int>& coins,vector<int>& dp,int amt) {
        if (amt==0) return 0;
        if(amt<0) return -1;

        if(dp[amt]!=-2) return dp[amt];


        int mini = 1e9;

        for(auto& coin : coins)
        {
            int take = fun(coins,dp,amt-coin);

            if(take>=0 && take<mini)
            {
                mini = 1 + take;
            } 
        }

        dp[amt] = (mini == 1e9) ? -1 : mini;
        return dp[amt];


    }


    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-2);

        return fun(coins,dp,amount);
    }
};
