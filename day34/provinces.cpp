class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<int>& v) {
        v[node] = 1;

        for(int next = 0; next < adj[node].size(); next++) {
            if(!v[next] && adj[node][next]) {
                dfs(next, adj, v);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int provinces = 0;  // local, not class member

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, isConnected, visited);
                provinces++;
            }
        }

        return provinces;
    }
};
