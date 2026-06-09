class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int enclaves = 0;

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i==0 || i == m-1 || j==0 || j==n-1) && grid[i][j]==1)
                {
                    q.push({i,j});
                    grid[i][j]=0;
                }
            }
        }

        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};


        while(!q.empty())
        {
            auto [r,c] = q.front();
            q.pop();

            for(auto& d : dirs)
            {
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr < 0 || nr >= m || nc < 0 || nc>=n) continue;

                if(grid[nr][nc]==1)
                {
                    grid[nr][nc] = 0;
                    q.push({nr,nc});
                }
            }
        }

        for(int i = 0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(grid[i][j]==1) enclaves++;
            }
        }



        return enclaves;
    }
};
