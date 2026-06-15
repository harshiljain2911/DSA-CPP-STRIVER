class Solution {
public:

    vector<int> parent,rank_;

    int findpar(int x) {

        if(parent[x]!=x)
        {
            parent[x] = findpar(parent[x]);
        }

        return parent[x];

    }


    void unite(int x,int y) {

        int px = parent[x];
        int py = parent[y];

        if(px==py) return;
        if(rank_[px]<rank_[py]) swap(px,py);
        parent[py]=px;
        if(rank_[px]==rank_[py]) rank_[px]++;

    }


    int maxRemove(vector<vector<int>>& stones, int n) {
      parent.resize(20002);
      rank_assign(20002,0);
      for(int i=0;i<20002;i++) parent[i]=i;

      for(auto& stone : stones)
      {
        int r = stone[0];
        int c = stone[1]+10001;

        unite(r,c);

      }

      unordered_set<int> root;
      for(auto& stone:stones)
      {
        roots.insert(find(stone[0]));
      }

      return n-root.size();
    }
};
