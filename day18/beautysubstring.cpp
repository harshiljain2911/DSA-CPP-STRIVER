class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;

        for(int i = 0; i < n; i++) {
            vector<int> frq(26, 0);

            for(int j = i; j < n; j++) {
                frq[s[j] - 'a']++;

                int maxn = 0;
                int minn = INT_MAX;

                for(int k = 0; k < 26; k++) {
                    if(frq[k] > 0) {
                        maxn = max(maxn, frq[k]);
                        minn = min(minn, frq[k]);
                    }
                }

                sum += (maxn - minn);
            }
        }

        return sum;
    }
};
