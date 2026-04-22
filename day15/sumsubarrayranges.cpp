class Solution {
public:

    vector<int> previousGreaterElements(const vector<int>& arr) {
        stack<int> st;
        vector<int> pge(arr.size());

        for(int i = 0; i < arr.size(); i++) {
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }

    vector<int> nextGreaterElements(const vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nge(n);

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }

    vector<int> previousSmallerElements(const vector<int>& arr) {
        stack<int> st;
        vector<int> pse(arr.size());

        for(int i = 0; i < arr.size(); i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    vector<int> nextSmallerElements(const vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n);

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> pge = previousGreaterElements(nums);
        vector<int> nge = nextGreaterElements(nums);
        vector<int> pse = previousSmallerElements(nums);
        vector<int> nse = nextSmallerElements(nums);

        long long totmax = 0, totmin = 0;

        for(int i = 0; i < n; i++) {
            long long leftmax = i - pge[i];
            long long rightmax = nge[i] - i;
            long long leftmin = i - pse[i];
            long long rightmin = nse[i] - i;

            totmax += (long long)nums[i] * leftmax * rightmax;
            totmin += (long long)nums[i] * leftmin * rightmin;
        }

        return totmax - totmin;
    }
};
