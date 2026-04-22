class Solution {
public:
    vector<int> previousSmallerElements(const vector<int>& arr) {
        stack<int> st;
        vector<int> pse(arr.size());  // FIXED

        for(int r = 0; r < arr.size(); r++)
        {
            while(!st.empty() && arr[st.top()] >= arr[r])
            {
                st.pop();
            }

            nse[r] = st.empty() ? -1 : st.top();

            st.push(r);
        }

        return pse;
    }
};
