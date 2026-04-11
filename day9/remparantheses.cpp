class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int depthcntr = 0;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i] == '(')
            {
                if(depthcntr>0)
                {
                    ans += s[i];
                }
                depthcntr++;
            }
            else if(s[i] == ')')
            {
                depthcntr--;
                if(depthcntr>0)
                {
                    ans += s[i];
                }
            }
        }

        return ans;
        
    }
};
