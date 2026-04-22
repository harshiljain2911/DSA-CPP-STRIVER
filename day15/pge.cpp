class Solution {
public:
    vector<int> previousGreaterElements(const vector<int>& arr) {
        stack<int> st;
        vector<int> pge(arr.size());

        for(int r = 0; r < arr.size(); r++)
        {
            while(!st.empty() && arr[st.top()] <= arr[r])
            {
                st.pop();
            }

            pge[r] = st.empty() ? -1 : st.top();

            st.push(r);
        }

        return pge;
    }
};
