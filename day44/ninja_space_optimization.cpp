class Solution {
public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int> dp(4, 0);

        dp[0] = max(matrix[0][1], matrix[0][2]);
        dp[1] = max(matrix[0][0], matrix[0][2]);
        dp[2] = max(matrix[0][0], matrix[0][1]);
        dp[3] = max(matrix[0][0],
                    max(matrix[0][1], matrix[0][2]));

        for (int day = 1; day < n; day++) {
            vector<int> temp(4, 0);

            for (int last = 0; last < 4; last++) {

                for (int task = 0; task < 3; task++) {

                    if (task != last) {
                        temp[last] = max(
                            temp[last],
                            matrix[day][task] + dp[task]
                        );
                    }
                }
            }

            dp = temp;
        }

        return dp[3];
    }
};
