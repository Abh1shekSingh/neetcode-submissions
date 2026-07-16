class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        vector<int> dist(n, INT_MAX);

        for(auto it: flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        dist[src] = 0;
        queue<pair<int, pair<int, int>>> que;
        que.push({0, {src, 0}});

        while(!que.empty()){
            int stops = que.front().first;
            int node = que.front().second.first;
            int cost = que.front().second.second;
            que.pop();

            if(stops > k) continue;

            for(auto it : adj[node]) {
                int price = it.second;
                int neigh = it.first;
                if(price + cost < dist[neigh] && stops <= k) {
                    dist[neigh] = price + cost;
                    que.push({stops + 1, {neigh, price + cost}});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
