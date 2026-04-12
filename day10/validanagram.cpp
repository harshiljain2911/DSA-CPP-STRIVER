class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(256, 0);

        if(s.size() != t.size()) return false;

        for(int i = 0; i < s.size(); i++) {
            v[s[i]]++;
            v[t[i]]--;
        }

        for(int x : v) {
            if(x != 0) return false;
        }

        return true;
    }
};
