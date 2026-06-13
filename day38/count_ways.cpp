class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const int mod = 1000000007;

        // Build adjacency list
        vector<vector<pair<long long, long long>>> adj(n);

        for (auto& city : roads) {
            long long u = city[0];
            long long v = city[1];
            long long w = city[2];

            adj[u].push_back({v, w});   // Bug 1 fixed: [] not ()
            adj[v].push_back({u, w});
        }

        // dist[i] = shortest time to reach node i
        vector<long long> dist(n, LLONG_MAX);

        // ways[i] = number of ways to reach node i in shortest time
        vector<long long> ways(n, 0);

        int src = 0;
        dist[src] = 0;
        ways[src] = 1;

        // Min-heap: {cost, node}
        priority_queue<pair<long long, long long>,
                       vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>> pq;

        pq.push({0, src});

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (cost > dist[node]) continue;

            for (auto [padosi, w] : adj[node]) {
                long long newDist = cost + w;

                if (newDist < dist[padosi]) {
                    // Found strictly shorter path → update and reset count
                    dist[padosi] = newDist;
                    ways[padosi] = ways[node];          // reset, not add
                    pq.push({dist[padosi], padosi});    // Bug 3 fixed
                }
                else if (newDist == dist[padosi]) {
                    // Found another path of same length → add count
                    ways[padosi] = (ways[padosi] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};
