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

    int getSize(int node) {
        return size[findUpar(node)];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Phase 1: union all land cells with their land neighbours
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue; // skip water in this pass

                int idx = i * n + j;

                for (int d = 0; d < 4; d++) {
                    int nr = i + dr[d];
                    int nc = j + dc[d];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        int nidx = nr * n + nc;
                        ds.unionBySize(idx, nidx);
                    }
                }
            }
        }

        int maxIsland = 0;
        bool hasWater = false;

        // Phase 2: try flipping every water cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) continue; // only consider water cells

                hasWater = true;
                set<int> uniqueRoots; // distinct islands touching this water cell
                int idx = i * n + j;

                for (int d = 0; d < 4; d++) {
                    int nr = i + dr[d];
                    int nc = j + dc[d];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        int nidx = nr * n + nc;
                        uniqueRoots.insert(ds.findUpar(nidx));
                    }
                }

                int total = 1; // the flipped cell itself
                for (int root : uniqueRoots) {
                    total += ds.getSize(root);
                }

                maxIsland = max(maxIsland, total);
            }
        }

        // If grid is all land, there's no water to flip — answer is n*n
        if (!hasWater) return n * n;

        return maxIsland;
    }
};
