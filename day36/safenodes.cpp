class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int m = graph.size();
        vector<int> outdegree(m, 0);
        vector<vector<int>> adj(m);
        vector<int> result;

        for (int i = 0; i < m; i++) {
            for (auto& g : graph[i]) {
                adj[g].push_back(i);   // reverse graph
                outdegree[i]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < m; i++) {
            if (outdegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            result.push_back(curr);

            for (auto &prev : adj[curr]) {
                outdegree[prev]--;
                if (outdegree[prev] == 0)
                    q.push(prev);
            }
        }

        sort(result.begin(), result.end());

        return result;
    }
};
