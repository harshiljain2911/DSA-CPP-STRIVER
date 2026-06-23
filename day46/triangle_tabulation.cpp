class Solution {
public:
    int minTriangleSum(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp = triangle;  // copy the triangle into dp
        
        // Start from second-last row, go up
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                dp[row][col] = triangle[row][col] + min(dp[row+1][col], dp[row+1][col+1]);
            }
        }
        
        return dp[0][0];  // answer is at the top
    }
};
