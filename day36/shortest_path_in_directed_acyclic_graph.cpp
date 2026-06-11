class Solution {
public:

    void topodfs(int node,
                 vector<vector<pair<int,int>>>& adj,
                 vector<int>& visited,
                 stack<int>& st)
    {
        visited[node] = true;

        for(auto &it : adj[node])
        {
            int padosi = it.first;

            if(!visited[padosi])
            {
                topodfs(padosi, adj, visited, st);
            }
        }

        st.push(node);
    }

    vector<int> shortestPath(int N, int M,
                             vector<vector<int>>& edges)
    {
        vector<vector<pair<int,int>>> adj(N);
        int src = 0;

        for(auto &current : edges)
        {
            int u = current[0];
            int v = current[1];
            int w = current[2];

            adj[u].push_back({v,w});
        }

        stack<int> st;
        vector<int> visited(N,false);

        for(int i=0;i<N;i++)
        {
            if(!visited[i])
            {
                topodfs(i,adj,visited,st);
            }
        }

        vector<int> dist(N,INT_MAX);
        dist[src] = 0;

        while(!st.empty())
        {
            int curr = st.top();
            st.pop();

            if(dist[curr] == INT_MAX)
                continue;

            for(auto &[padosi,w] : adj[curr])
            {
                if(dist[curr] + w < dist[padosi])
                {
                    dist[padosi] = dist[curr] + w;
                }
            }
        }

        for(int i=0;i<N;i++)
        {
            if(dist[i] == INT_MAX)
            {
                dist[i] = -1;
            }
        }

        return dist;
    }
};
