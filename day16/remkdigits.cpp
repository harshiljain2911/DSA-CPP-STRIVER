class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (char digit : num) {
            while (!st.empty() && st.top() > digit && k > 0) {
                st.pop();
                k--;
            }
            st.push(digit);
        }

        // If k still remains, remove from end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Build result string
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        // Remove leading zeros
        int i = 0;
        while (i < ans.size() && ans[i] == '0') i++;

        ans = ans.substr(i,ans.size());

        // If empty, return "0"
        return ans.empty() ? "0" : ans;
    }
};
