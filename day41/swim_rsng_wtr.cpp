class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue><vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<bool>> visited(n,vector<bool>(n,false));

        pq.push({grid[0][0],0,0});
        visited[0][0] = true;

        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

        int ans = 0;

        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int elevation = top[0], r = top[1], c = top[2];

            ans = max(ans,elevation);

            for(int d: dirs)
            {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    pq.push({grid[nr][nc], nr, nc});
                }
            }

        }

        return ans;
    }
};
