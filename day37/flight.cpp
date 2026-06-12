class Solution{
public:
    int CheapestFlight(int n, vector<vector<int>> &flights,
                       int src, int dst, int K) {
         
         
        vector<vector<pair<int,int>>> adj(n);

        for(auto& f : flights)
        {
            adj[f[0]].push_back({f[1],f[2]});
        }

        vector<vector<int>> dist (n,vector<int>(k+2,INT_MAX));
        dist[src][0] = 0;

        priority_queue<tuple<int,int,int>,<vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        pq.push({0,src,0});

        while(!pq.empty())
        {
            auto [cost,node,stops] = pq.top();
            pq.pop();

            if(node == dst) return cost;

            if(stops > k) continue;

            for(auto& [padosi,price]:adj[node])
            {
                int newCost = cost + price;
                if(newCost < dist[padosi][stops + 1])
                {
                    dist[padosi][stops + 1] = newCost;
                    pq.push({newCost, padosi , stops + 1});
                }
            }
        }

        return -1;

    }
};
