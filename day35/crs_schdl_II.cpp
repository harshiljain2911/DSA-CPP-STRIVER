class Solution {
  public: vector < int > findOrder(int N, vector < vector < int >> arr) {
   vector<vector<int>> adj(N);
        vector<int> indegree(N,0);

        for(auto& a : arr)
        {
            int pre = a[1];
            int crs = a[0];

            adj[pre].push_back(crs);
            indegree[crs]++;
        }

        queue<int> q;
        vector<int> result;

        for(int i=0;i<N;i++)
        {
            if(indegree[i]==0) q.push(i);
        }

        

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            result.push_back(curr);

            for(int nxt : adj[curr])
            {
                indegree[nxt]--;

                if(indegree[nxt]==0) q.push(nxt);
            }

        }

        if (result.size() == N) {
            return result;
        }
        return {};

  }
};

