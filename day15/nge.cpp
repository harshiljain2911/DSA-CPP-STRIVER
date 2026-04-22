class Solution {
public:
    vector<int> nextGreaterElements(const vector<int>& arr) {
        stack<int> st;
        vector<int> nge(arr.size());

        for(int r = arr.size()-1; r >= 0; r--)
        {
            while(!st.empty() && arr[st.top()] <= arr[r])
            {
                st.pop();
            }

            nge[r] = st.empty() ? n : st.top();

            st.push(r);
        }

        return nge;
    }
};
