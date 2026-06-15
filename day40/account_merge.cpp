class Solution {
public:

    class DisjointSet {
    public:
        vector<int> parent, rank_, size;

        DisjointSet(int n) {
            rank_.resize(n, 0);
            size.resize(n, 1);
            parent.resize(n);

            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int findUpar(int node) {
            if (node == parent[node])
                return node;

            return parent[node] = findUpar(parent[node]);
        }

        void unionBySize(int u, int v) {
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);

            if (ulp_u == ulp_v) return;

            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        DisjointSet ds(n);

        unordered_map<string, int> MailID;

        // Union accounts having common emails
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {

                string mail = accounts[i][j];

                if (MailID.find(mail) == MailID.end()) {
                    MailID[mail] = i;
                }
                else {
                    ds.unionBySize(i, MailID[mail]);
                }
            }
        }

        // Store emails according to their ultimate parent
        vector<vector<string>> mergedMails(n);

        for (auto &it : MailID) {
            string mail = it.first;
            int node = ds.findUpar(it.second);

            mergedMails[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {

            if (mergedMails[i].empty()) continue;

            sort(mergedMails[i].begin(), mergedMails[i].end());

            vector<string> temp;

            // Account name
            temp.push_back(accounts[i][0]);

            // Emails
            for (auto &mail : mergedMails[i]) {
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
