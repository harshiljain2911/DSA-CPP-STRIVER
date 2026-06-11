class Solution {
public:
	string findOrder(string dict[], int N, int K) {
		// Step 1: Initialize indegree for all unique characters
        unordered_map<char, int> indegree;
        unordered_map<char, vector<char>> adj;

        for (auto& word : dict) {
            for (char c : word) {
                if (indegree.find(c) == indegree.end()) {
                    indegree[c] = 0;
                    adj[c] = {};
                }
            }
        }

        // Step 2: Compare adjacent words to extract ordering rules
        for (int i = 0; i < words.size() - 1; i++) {
            string& w1 = words[i];
            string& w2 = words[i + 1];
            int minLen = min(w1.size(), w2.size());

            // Special case: "abc" before "ab" is invalid
            if (w1.size() > w2.size() && w1.substr(0, minLen) == w2) {
                return "";
            }

            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    // w1[j] comes before w2[j]
                    adj[w1[j]].push_back(w2[j]);
                    indegree[w2[j]]++;
                    break; // Only first difference matters
                }
            }
        }

        // Step 3: BFS Kahn's algorithm
        queue<char> q;
        for (auto& [c, deg] : indegree) {
            if (deg == 0) q.push(c);
        }

        string result = "";
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            result += curr;

            for (char neighbor : adj[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: Cycle check
        if (result.size() != indegree.size()) return "";

        return result;
	}
};
