class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) dist[i][j]=0;
            }
        }

        for (auto& e : edges) {
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }


        // Step 2: Floyd-Warshall — try every city as intermediate
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

         // Step 3: For each city, count reachable cities within threshold
        int resultCity = -1;
        int minCount = n; // can't have more than n neighbors

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold)
                    count++;
            }

            // Pick city with fewer neighbors; on tie, prefer higher index
            // >= handles tie-breaking: higher index overwrites equal minCount
            if (count <= minCount) {
                minCount = count;
                resultCity = i;
            }
        }

        return resultCity;
    }
};
