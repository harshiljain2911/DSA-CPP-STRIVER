class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = 1e9;

        // dist[i] = cheapest price to reach node i
        vector<int> dist(n, INF);
        dist[src] = 0;

        // K stops = K+1 edges = K+1 passes
        for (int i = 0; i <= k; i++) {

            // CRITICAL: copy dist so this pass doesn't use
            // updates made within the same pass
            vector<int> temp = dist;

            for (auto& flight : flights) {
                int u = flight[0];  // from
                int v = flight[1];  // to
                int w = flight[2];  // price

                // Relax into temp, read from dist
                if (dist[u] != INF && dist[u] + w < temp[v]) {
                    temp[v] = dist[u] + w;
                }
            }

            // Commit this pass's updates
            dist = temp;
        }

        return dist[dst] == INF ? -1 : dist[dst];
    }
};
