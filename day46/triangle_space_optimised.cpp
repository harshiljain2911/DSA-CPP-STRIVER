class Solution {
public:
    int minTriangleSum(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(triangle[n-1]);  // initialize with last row
        
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                dp[col] = triangle[row][col] + min(dp[col], dp[col+1]);
                //         current cell      +  left child  right child
            }
        }
        
        return dp[0];
    }
};
