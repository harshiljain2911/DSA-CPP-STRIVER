class Solution{	
	public:
		vector<char> frequencySort(string& s){
			unordered_map<char,int> freq;

            for (char c : s) {
                freq[c]++;
            }

            vector<pair<char, int>> vec(freq.begin(), freq.end());

            sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
                return a.second > b.second;
            });

            vector<char> ans;

            for (auto &p : vec) {
                
                    ans.push_back(p.first);
                
            }

            return ans;
		}
};
