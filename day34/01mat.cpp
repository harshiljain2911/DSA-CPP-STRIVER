class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> dist(rows,vector<int> (cols,-1));
        queue<pair<int,int>> q;

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(mat[i][j]==0) 
                {
                    
                    dist[i][j]=0;
                    q.push({i,j});

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

                if( nr<0 || nr>= rows || nc<0 || nc>=cols) continue;

                if(dist[nr][nc] != -1) continue;

                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr,nc});
            }
        }

        return dist;


    }
};
