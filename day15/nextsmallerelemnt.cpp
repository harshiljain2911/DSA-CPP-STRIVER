class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            nse[i] = st.empty() ? -1 : arr[st.top()];

            st.push(i);
        }

        return nse;
    }
};
