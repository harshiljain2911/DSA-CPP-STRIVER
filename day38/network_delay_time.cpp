class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build adjacency list (1-indexed, so size n+1)
        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        // Distance array, all infinity except source
        vector<int> tm(n + 1, INT_MAX);
        tm[k] = 0;

        // Min-heap: {cost, node}
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        pq.push({0, k});

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            // Skip if we already found a better path to this node
            if (cost > tm[node]) continue;

            for (auto [padosi, time] : adj[node]) {
                if (tm[padosi] > cost + time) {       // BUG 2 fixed: > not 
                    tm[padosi] = cost + time;
                    pq.push({tm[padosi], padosi});
                }
            }
        }

        // Find max time across all nodes (1..n)
        int ans = *max_element(tm.begin() + 1, tm.end());
        return ans == INT_MAX ? -1 : ans;
    }
};
