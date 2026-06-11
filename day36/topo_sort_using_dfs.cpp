class Solution {
public:

    void dfs(int node,
             vector<vector<int>>& adj,
             vector<bool>& visited,
             stack<int>& st)
    {
        visited[node] = true;

        for(int padosi : adj[node])
        {
            if(!visited[padosi])
            {
                dfs(padosi, adj, visited, st);
            }
        }

        st.push(node);
    }

    vector<int> topoSort(int n, vector<vector<int>>& adj)
    {
        vector<bool> visited(n, false);
        stack<int> st;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                dfs(i, adj, visited, st);
            }
        }

        vector<int> result;

        while(!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};
