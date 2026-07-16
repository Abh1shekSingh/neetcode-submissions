class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        queue<pair<int, int>> que;
        que.push({k, 0});

        while(!que.empty()) {
            int node = que.front().first;
            int time = que.front().second;
            que.pop();

            if(time > dist[node]) continue;
            for(auto it : adj[node]) {
                if(time + it.second < dist[it.first]) {
                    dist[it.first] = time + it.second;
                    que.push({it.first,time + it.second});
                }
            }
        }
        int res = 0;
        res = *max_element(dist.begin() + 1, dist.end());
        return res == INT_MAX ? -1 : res;
    }
};
