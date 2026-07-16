class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        set<pair<int, int>> vis;
        priority_queue<vector<int>,
                       vector<vector<int>>, greater<>> que;
        que.push({grid[0][0],0, 0});
        vis.insert({0, 0});
        while(!que.empty()) {
            auto it = que.top();
            que.pop();
            int time = it[0];
            int row = it[1];
            int col = it[2];
            if(row == n - 1 && col == n - 1) {
                return time;
            }
            for(int i = 0 ; i < 4 ; i++) {
                int newR = row + dx[i];
                int newC = col + dy[i];
                if(newR >= 0 && newR < n &&
                   newC >= 0 && newC < n &&
                   !vis.count({newR, newC})) {
                    vis.insert({newR, newC});
                    que.push({max(time, grid[newR][newC]), newR, newC});
                   }
            }
        }
        return -1;
    }
};
