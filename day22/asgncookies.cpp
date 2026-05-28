class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0;
        int j = 0;
        int ans = 0;

        while (i < g.size() && j < s.size()) {

            // cookie can satisfy child
            if (g[i] <= s[j]) {

                ans++;
                i++;
                j++;
            }

            // cookie too small
            else {

                j++;
            }
        }

        return ans;
    }
};
