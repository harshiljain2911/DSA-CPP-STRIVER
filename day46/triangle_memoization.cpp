class Solution {
public:

    int fun(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(i == triangle.size()-1) return triangle[i][j];

        if(dp[i][j]!=INT_MIN) return dp[i][j];

        int down = fun(i+1,j,triangle,dp);
        int downright = fun(i+1,j+1,triangle,dp);

        return dp[i][j] = triangle[i][j] + min(down,downright);

    }

    int minTriangleSum(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),INT_MIN));

        return fun(0,0,triangle,dp);
    }
};
