class Solution{
public:
    int shortestPath(vector<vector<int>> &grid,
                     pair<int,int> source,
                     pair<int,int> destination)
    {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[source.first][source.second] == 1 ||
           grid[destination.first][destination.second] == 1)
            return -1;

        if(source == destination)
            return 0;

        int dirs[4][2] = {
            {0,1},{1,0},{0,-1},{-1,0}
        };

        queue<tuple<int,int,int>> q;

        q.push({source.first, source.second, 0});

        grid[source.first][source.second] = 1;

        while(!q.empty())
        {
            auto [r,c,dist] = q.front();
            q.pop();

            for(auto &d : dirs)
            {
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                if(grid[nr][nc] == 1)
                    continue;

                if(nr == destination.first &&
                   nc == destination.second)
                    return dist + 1;

                grid[nr][nc] = 1;
                q.push({nr,nc,dist+1});
            }
        }

        return -1;
    }
};
