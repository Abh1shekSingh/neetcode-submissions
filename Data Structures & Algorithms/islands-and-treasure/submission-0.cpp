class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int solve(int row, int col, vector<vector<int>>& grid, int n, int m) {
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> que;
        que.push({row, col});
        vis[row][col] = 1;
        int cnt = 0;
        while(!que.empty()) {
            int size  = que.size();
            while(size--) {
                int r = que.front().first;
                int c = que.front().second;
                que.pop();
                if(grid[r][c] == 0) return cnt;
                for(int i = 0 ; i < 4 ; i++) {
                    int newR = r + dx[i];
                    int newC = c + dy[i];
                    if(newR >= 0 && newR < n && newC >= 0 && newC < m && grid[newR][newC] != -1 && !vis[newR][newC]) {
                        que.push({newR, newC});
                        vis[newR][newC] = 1;
                    }
                }
            }
            cnt++;
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == 2147483647) {
                    grid[i][j] = solve(i, j, grid, n, m);
                }
            }
        }
    }
};
