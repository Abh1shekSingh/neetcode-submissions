class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int, vector<pair<int, int>>> adj;
        set<int> vis;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
        int n = points.size();
        for(int i = 0 ; i < n ; i++) {
            for(int j = i + 1 ; j < n ; j++) {
                int dist = abs((points[i][0] - points[j][0])) + abs((points[i][1] - points[j][1]));
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }

        minH.push({0, 0});
        int ans = 0;
        while(!minH.empty()) {
            int size = minH.size();
            while(size--) {
                int cost = minH.top().first;
                int node = minH.top().second;
                minH.pop();
                if(vis.count(node)) continue;
                vis.insert(node);
                ans += cost;
                for(auto it : adj[node]) {
                    if(!vis.count(it.second)) {
                        minH.push({it.first, it.second});
                    }
                }
            }
        }
        return ans;
    }
};
