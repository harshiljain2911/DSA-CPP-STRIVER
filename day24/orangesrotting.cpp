class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // Step 1: Find all rotten oranges and count fresh ones
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2)
                    q.push({i, j});       // All rotten oranges are sources
                else if(grid[i][j] == 1)
                    fresh++;              // Count fresh oranges
            }
        }

        // Step 2: Early exit
        if(fresh == 0) return 0;

        // Step 3: BFS — spread rot level by level
        int minutes = 0;
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty()) {
            int sz = q.size();            // Process current wave only
            minutes++;

            for(int k = 0; k < sz; k++) {
                auto [row, col] = q.front();
                q.pop();

                for(auto& d : dirs) {
                    int nr = row + d[0];
                    int nc = col + d[1];

                    // Skip out-of-bounds or non-fresh cells
                    if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;
                    if(grid[nr][nc] != 1)
                        continue;

                    grid[nr][nc] = 2;     // Rot the fresh orange
                    fresh--;              // One less fresh orange
                    q.push({nr, nc});     // Add to next wave
                }
            }
        }

        return (fresh == 0) ? minutes - 1 : -1;
    }
};
