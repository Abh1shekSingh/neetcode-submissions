class Solution {
public:
    int find(int node, vector<int>& par) {
        if(node == par[node]) return node;
        return par[node] = find(par[node], par);
    }
    bool Union(int u, int v, vector<int>& par, vector<int>& size) {
        int uP = find(u, par);
        int vP = find(v, par);
        if(uP == vP) return false;
        if(size[uP] < size[vP]) {
            par[uP] = vP;
            size[vP] += size[uP]; 
        }else {
            par[vP] = uP;
            size[uP] += size[vP];
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n + 1), size(n + 1, 1);
        for(int i = 0 ; i <= n ; i++) {
            par[i] = i;
        }
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            if(!Union(u,v, par, size)) {
                return {u, v};
            }
        }
        return {};
    }
};
