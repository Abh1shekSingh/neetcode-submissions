class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> que;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int res = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    que.push({i, j});
                    vis[i][j] = 1;
                    int ans = 1;
                    while(!que.empty()) {
                        int row = que.front().first;
                        int col = que.front().second;
                        que.pop();
                        for(int del = 0 ; del < 4 ; del++) {
                            int newR = row + dx[del];
                            int newC = col + dy[del];
                            if(newR >= 0 && newR < n && newC >= 0 && newC < m && !vis[newR][newC] && grid[newR][newC]) {
                                que.push({newR, newC});
                                vis[newR][newC] = 1;
                                ans++;
                            }
                        }
                    }
                    res = max(res, ans);
                }
            }
        }
        return res;
    }
};
