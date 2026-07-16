class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> pq;
    vector<string> res;
    void solve(string u) {
        auto &edges = pq[u];
        while(!edges.empty()) {
            string node = edges.top();
            edges.pop();
            solve(node);
        }
        res.push_back(u);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto it : tickets) {
            pq[it[0]].push(it[1]);
        }
        solve("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};
