class Solution {
public:
    bool rotateString(string s, string goal) {
        string dbls = s+s;
        if(s.size()!=goal.size()) return false;
        else
        {
            if(dbls.find(goal) != string::npos) return true;
            else return false;
        }
    }
};
