class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int counter = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    counter++;                    // count ALL 1's first
                }
                if((i == 0 || i == m-1 || j == 0 || j == n-1)
                    && grid[i][j] == 1) {
                    counter--;                    // border 1 → not enclosed
                    grid[i][j] = 2;              // mark visited
                    q.push({i, j});
                }
            }
        }

        int dirs[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for(auto& d : dirs) {
                int nr = row + d[0];
                int nc = col + d[1];

                if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                if(grid[nr][nc] == 1) {
                    counter--;                    // border-connected → not enclosed
                    grid[nr][nc] = 2;            // mark visited
                    q.push({nr, nc});
                }
            }
        }

        return counter;    // only enclosed 1's remain
    }
};
