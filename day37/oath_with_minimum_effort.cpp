class Solution
{
public:
    int MinimumEffort(vector<vector<int>> &heights)
    {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> effort(rows,vector<int>(cols,INT_MAX));
        effort[0][0] = 0;

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>,greater<tuple<int,int,int>>> pq;
        pq.push({0,0,0});

        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

        while(!pq.empty())
        {
            auto [eff,r,c] = pq.top();
            pq.pop();

            if(r==rows-1 && c==cols-1) return eff;

            if(eff > effort[r][c]) continue;

            for(auto d : dirs)
            {
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr<0 || nr>=rows || nc<0 || nc>=cols) continue;

                int newEff = max(eff, abs(heights[r][c]-heights[nr][nc]));

                if(newEff < effort[nr][nc])
                {
                    effort[nr][nc] = newEff;
                    pq.push({newEff,nr,nc});
                }

            }
        }

        return 0;


    }
};

