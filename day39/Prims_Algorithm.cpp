class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int,int>>> pq;
       vector<int> visited(V,0);

       pq.push({0,0}); // weight,source

       int sum = 0;

       while(!pq.empty())
       {
        auto it = pq.top();
        pq.pop();

        int node = it.second;
        int w = it.first;

        if(visited[node]==1) continue;

        visited[node]=1;
        sum += w;

        for(auto& edge = adj[node])
        {
            int padosi = edge[0];
            int wt = edge[1];
            if(!visited[padosi])
            {
                pq.push({wt,padosi});
            }
        }
       }

       return sum;
    }
};
