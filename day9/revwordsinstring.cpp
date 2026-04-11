class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i = s.size() - 1;

        while(i >= 0) {

            // skip spaces
            while(i >= 0 && s[i] == ' ') i--;

            if(i < 0) break;

            string word = "";

            // build word
            while(i >= 0 && s[i] != ' ') {
                word += s[i];
                i--;
            }

            reverse(word.begin(), word.end());

            if(ans.size() > 0) ans += " ";
            ans += word;
        }

        return ans;
    }
};
