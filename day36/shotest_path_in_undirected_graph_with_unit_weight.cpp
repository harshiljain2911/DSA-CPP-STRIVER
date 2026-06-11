class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M) {

        vector<vector<int>> adj(N);

        for(int i = 0; i < M; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int src = 0;

        vector<int> dist(N, INT_MAX);
        dist[src] = 0;

        queue<int> q;
        q.push(src);

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            for(int padosi : adj[curr])
            {
                if(dist[curr] + 1 < dist[padosi])
                {
                    dist[padosi] = dist[curr] + 1;
                    q.push(padosi);
                }
            }
        }

        for(int i = 0; i < N; i++)
        {
            if(dist[i] == INT_MAX)
                dist[i] = -1;
        }

        return dist;
    }
};
