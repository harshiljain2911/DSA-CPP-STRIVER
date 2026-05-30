class Solution{
public:
    vector<vector<int>> nearest(vector<vector<int>> grid){
   int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto& d : dirs) {
                int nr = row + d[0];
                int nc = col + d[1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                    continue;
                }

                if (dist[row][col] + 1 < dist[nr][nc]) {
                    dist[nr][nc] = dist[row][col] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return dist;
    }
    }
};
