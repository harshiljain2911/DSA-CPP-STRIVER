class Solution {
public:

    void bfs(vector<vector<char>>& grid, int i, int j)
    {
        queue<pair<int,int>> q;
        q.push({i,j});

        grid[i][j] = '0';

        int dirs[8][2] = {
            {1,0},   // down
            {-1,0},  // up
            {0,1},   // right
            {0,-1},  // left
            {1,1},   // down-right
            {-1,-1}, // up-left
            {-1,1},  // up-right
            {1,-1}   // down-left
        };

        while(!q.empty())
        {
            auto [r,c] = q.front();
            q.pop();

            for(auto &d : dirs)
            {
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr >= 0 && nr < grid.size() &&
                   nc >= 0 && nc < grid[0].size() &&
                   grid[nr][nc] == '1')
                {
                    grid[nr][nc] = '0';
                    q.push({nr,nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int islands = 0;

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    islands++;
                    bfs(grid, i, j);
                }
            }
        }

        return islands;
    }
};
