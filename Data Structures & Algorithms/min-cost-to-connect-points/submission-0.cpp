class Solution {
public:
    int findUPar(int node, vector<int>& parent) {
        if(node == parent[node]) return node;
        return parent[node]=findUPar(parent[node], parent);
    }
    bool Union(int u, int v, vector<int>& parent, vector<int>& size) {
        int U_P = findUPar(u, parent);
        int V_P = findUPar(v, parent);

        if(U_P == V_P) return false;
        if(size[U_P] < size[V_P]) {
            parent[U_P] = V_P;
            size[V_P] += size[U_P];
        }else {
            parent[V_P] = U_P;
            size[U_P] += size[V_P];
        }
        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> parent(n + 1);
        vector<int> size(n + 1, 1);

        for(int i = 0 ; i <= n ; i++) {
            parent[i] = i;
        }

        vector<pair<int, pair<int, int>>> adj;

        for(int i = 0 ; i < n ; i++) {
            for(int j = i + 1 ; j < n ; j++) {
                int distance = abs((points[i][0] - points[j][0])) + abs((points[i][1] - points[j][1])); 
                adj.push_back({distance, {i, j}});
            }
        }
        sort(adj.begin(), adj.end());
        int ans = 0;
        for(auto it : adj) {
            int u = it.second.first;
            int v = it.second.second;
            if(Union(u, v, parent, size)) {
                ans += it.first;
            }
        }
        return ans;
    }
};
