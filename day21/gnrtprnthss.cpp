class Solution {
public:

    void solve(int n,vector<string> ans ,string current,int open,int close) {

        if(current.length()==2*n)
        {
            ans.push_back(current);
            return;
        }

        if(open < n)
        {
            solve(n,ans,current + "(",open+1,close);
        }

        if(close<open)
        {
            solve(n,ans,current + ")",open,close+1);
        }


    }

    vector<string> generateParenthesis(int n) {
        
        vector <string> ans;
        solve(n,ans,"",0,0);
        return ans;

    }
};
