class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) fresh++;
            }
        }

        if(fresh==0) return 0;

        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int minutes = 0;

        while(!q.empty())
        {
            int size = q.size();
            minutes++;

            for(int k=0;k<size;k++)
            {
                auto [r,c] = q.front();
                q.pop();

                for(auto &d : dirs)
                {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if(nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                    {
                        continue;
                    }
                    if(grid[nr][nc]!=1) continue;

                    grid[nr][nc]=2;
                    fresh--;
                    q.push({nr,nc});
                }
            }
        } 

        return fresh == 0 ? minutes - 1 : -1;
    }
};
