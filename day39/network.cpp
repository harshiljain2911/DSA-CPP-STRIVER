class Solution{
public:

    vector<int> parent,rank_;

    int findpar(int x) {
        if(parent[x]==x) return parent[x];
        return parent[x] = findpar(parent[x]);
    }

    void union(int x,int y) {
        int px = findpar(x);
        int py = findpar(y);

        if(px==py) return;

        if(rank_[px]<rank_[py])
        {
            parent[px] = py;
        }
        else if(rank_[py]<rank_[px])
        {
            parent[py] = px;
        }
        else
        {
            parent[py] = px;
            rank_[px]++;
        }
    }

    int solve(int n, vector<vector<int>> &Edge){
        if(edges.size()<n-1)
        {
            return -1;
        }

        parent.resize(n);
        rank_.assign(n,0);

        for (int i = 0; i < n; i++) parent[i] = i;

        for (auto &e : edges) {
            unite(e[0], e[1]);
        }

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i) components++;
        }

        return components - 1;
    }
};
