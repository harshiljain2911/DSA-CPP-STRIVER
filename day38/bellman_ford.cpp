class Solution {
public:
	vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        const int INF = 1e9;

    vector<int> dist(V, INF);
    dist[S] = 0;

    // V-1 relaxation passes
    for (int i = 0; i < V - 1; i++) {
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Vth pass: negative cycle detection
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            return {-1};  // negative cycle
        }
    }

    return dist;
	}
};
