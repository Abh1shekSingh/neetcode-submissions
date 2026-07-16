class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        for (string w : words) {
            for (char c : w) {
                adj[c] = unordered_set<char>();
                indegree[c] = 0;
            }
        }
        for(int i = 0 ; i < words.size() - 1 ; i++) {
            string a = words[i];
            string b = words[i + 1];

            int minL = min(a.size(), b.size());

            if(a.size() > b.size() && a.substr(0, minL) == b.substr(0, minL)) return "";

            for(int j = 0 ; j < minL ; j++) {
                if(a[j] != b[j]) {
                    if(!adj[a[j]].count(b[j])){
                        adj[a[j]].insert(b[j]);
                        indegree[b[j]]++;
                    }
                    break;
                }
            }
        }
        queue<char> que;
        for(auto it : indegree) {
            if(it.second == 0) {
                que.push(it.first);
            }
        }

        string ans = "";
        while(!que.empty()) {
            char ch = que.front();
            que.pop();
            ans += ch;
            for(auto it : adj[ch]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    que.push(it);
                }
            }
        }
        
        return ans.size() == indegree.size() ? ans : "";
    }
};
