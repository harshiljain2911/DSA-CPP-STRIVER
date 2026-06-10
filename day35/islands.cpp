class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {

        grid[r][c] = '0';

    int dirs[8][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1},{1,1},{1,-1},{-1,1},{-1,-1}};

        for (auto& d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size())
                continue;

            if (grid[nr][nc] == '1') {
                dfs(grid, nr, nc);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j);
                    
                }
            }
        }

        return islands;
    }
};
