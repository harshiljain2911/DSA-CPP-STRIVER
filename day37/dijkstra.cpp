class Solution{
public:
    vector<int> dijkstra(int V, vector<vector<int>> edges, int S) {

        vector<vector<pair<int,int>>> adj(V);

        
            for(auto& current:edges)
            {
                int u = current[0];
                int v = current[1];
                int w = current[2];

                adj[u].push_back({v,w});
                adj[v].push_back({u,w});

            }
        
        vector<int> dist(V,INT_MAX);
        dist[S] = 0;

        priority_queue<pair<int,int>,
               vector<pair<int,int>>,
               greater<pair<int,int>>> pq;

        pq.push({0,S});

        while(!pq.empty())
        {
            auto [d,curr] = pq.top();
            pq.pop();

            if(d > dist[curr]) continue;

            for(auto& [padosi,weight] : adj[curr])
            {
                if(dist[curr] + weight < dist[padosi])
                {
                    dist[padosi] = dist[curr] + weight;
                    pq.push({dist[padosi],padosi});
                }
            }

        }

        return dist;
    }
};
