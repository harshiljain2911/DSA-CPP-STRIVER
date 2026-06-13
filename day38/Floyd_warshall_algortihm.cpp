class Solution {
public:
	void shortestDistance(vector<vector<int>>&matrix) {
        int n = matrix.size();

        // Step 1: Replace -1 with INT_MAX equivalent (large number)
        // But since output needs -1, use a large sentinel instead
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1)
                    matrix[i][j] = 1e9;  // treat as infinity
            }
        }

        // Step 2: Floyd-Warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    // Skip if path through k is impossible
                    if (matrix[i][k] == 1e9 || matrix[k][j] == 1e9)
                        continue;

                    matrix[i][j] = min(matrix[i][j],
                                       matrix[i][k] + matrix[k][j]);
                }
            }
        }

        // Step 3: Replace sentinel back with -1 for unreachable pairs
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1e9)
                    matrix[i][j] = -1;
            }
        }
	}
};
