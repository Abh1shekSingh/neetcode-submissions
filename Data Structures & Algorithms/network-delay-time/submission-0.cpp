class Solution {
public:
    void dfs(int node, int time, vector<int>& dist, unordered_map<int, vector<pair<int, int>>>& adj) {
        if(time >= dist[node]) return ;
        dist[node] = time;
        for(auto it : adj[node]) {
            dfs(it.first, time + it.second, dist, adj);
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      unordered_map<int, vector<pair<int, int>>> adj;
      for(auto it : times) {
        adj[it[0]].push_back({it[1], it[2]});
      }  

      vector<int> dist(n + 1, INT_MAX);
    
      dfs(k, 0, dist, adj);
    
        int res = *max_element(dist.begin() + 1, dist.end());
        return res == INT_MAX ? -1 : res ;

    }
};
