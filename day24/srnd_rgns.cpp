class Solution{
public:
    vector<vector<char>> fill(vector<vector<char>> mat) {
       int m = board.size();
        int n = board[0].size();

        queue<pair<int,int>> q;

        // Step 1: Push ONLY border O's
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if((i == 0 || i == m-1 || j == 0 || j == n-1)
                    && board[i][j] == 'O') {
                    q.push({i, j});
                    board[i][j] = 'S';    // mark as safe
                }
            }
        }

        int dirs[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

        // Step 2: BFS — spread safety to all connected O's
        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for(auto& d : dirs) {
                int nr = row + d[0];
                int nc = col + d[1];

                // Fixed boundary check
                if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                // Only spread to unvisited O's
                if(board[nr][nc] == 'O') {
                    board[nr][nc] = 'S';   // mark as safe
                    q.push({nr, nc});
                }
            }
        }

        // Step 3: Final pass — flip remaining O's, restore S's
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';  // surrounded
                else if(board[i][j] == 'S') board[i][j] = 'O';  // safe
            }
        }
    }
    }
};
