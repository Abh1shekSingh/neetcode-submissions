class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        set<int> vis;

        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        queue<pair<int, int>> que;
        que.push({0, -1});
        vis.insert(0);

        while(!que.empty()) {
            int node = que.front().first;
            int parent = que.front().second;
            que.pop();
            for(auto it : adj[node]) {
                if(it == parent) continue;
                if(vis.count(it)) return false;

                que.push({it, node});
                vis.insert(it);
            }
        }
        return vis.size() == n;
    }
};
