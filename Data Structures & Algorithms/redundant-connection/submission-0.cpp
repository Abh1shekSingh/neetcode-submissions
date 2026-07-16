class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis) {
        if(vis[node]) return true;
        vis[node] = 1;

        for(auto it : adj[node]) {
           if(it == parent) continue;
           if(dfs(it, node, adj, vis)) return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
            vector<int> vis(n + 1, 0);
            if(dfs(u, -1, adj, vis)) return {u, v};
        }
        return {};
    }
};
