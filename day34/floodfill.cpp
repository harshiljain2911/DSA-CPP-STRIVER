class Solution {
public:

    void dfs(vector<vector<int>>& image, int start_clr, int clr, int r, int c) {
        
        image[r][c] = clr;  // color current cell (acts as visited marker too)

        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

        for(auto& d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if(nr < 0 || nr >= (int)image.size() || nc < 0 || nc >= (int)image[0].size()) continue;

            if(image[nr][nc] == start_clr) {   // unvisited + correct color (same check now)
                dfs(image, start_clr, clr, nr, nc);  // RECURSE
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start_clr = image[sr][sc];

        if(start_clr == color) return image;  // edge case: nothing to do

        dfs(image, start_clr, color, sr, sc);

        return image;
    }
};
