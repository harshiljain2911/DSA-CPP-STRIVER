class DisjointSet {
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUpar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>>& A) {
        int k = A.size();
        DisjointSet ds(n * m);                     // 1D indexed DSU for n*m grid
        vector<bool> visited(n * m, false);
        vector<int> result;
        int islandCount = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < k; i++) {
            int r = A[i][0];
            int c = A[i][1];
            int idx = r * m + c;                   // flatten 2D → 1D

            if (visited[idx]) {                    // duplicate operation
                result.push_back(islandCount);
                continue;
            }

            visited[idx] = true;
            islandCount++;                         // new land = new island

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                int nidx = nr * m + nc;

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && visited[nidx]) {
                    // neighbour is land — if different component, merge
                    if (ds.findUpar(idx) != ds.findUpar(nidx)) {
                        ds.unionBySize(idx, nidx);
                        islandCount--;             // two islands became one
                    }
                }
            }

            result.push_back(islandCount);
        }

        return result;
    }
};
