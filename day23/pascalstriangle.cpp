class Solution {
public:
    int pascalTriangleI(int r, int c) {

        int numRows = r+1;

        vector<vector<int>> ans(numRows);

        for (int i = 0; i < numRows; i++) {

            for (int j = 0; j <= i; j++) {

                if (j == 0 || j == i) {
                    ans[i].push_back(1);
                }
                else {
                    ans[i].push_back(
                        ans[i-1][j-1] + ans[i-1][j]
                    );
                }
            }
        }

        return ans[r-1][c-1];
    }
};
