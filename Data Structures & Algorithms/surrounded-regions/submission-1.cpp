class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> que;

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if(board[i][j] == 'O') {
                        que.push({i,j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        while(!que.empty()) {
            int row = que.front().first;
            int col = que.front().second;
            que.pop();
            for(int i = 0 ; i < 4 ; i++) {
                int newR = row + dx[i];
                int newC = col + dy[i];
                if(newR >= 0 && newR < n &&
                   newC >= 0 && newC < m &&
                   board[newR][newC] == 'O' && !vis[newR][newC]){
                    que.push({newR, newC});
                    vis[newR][newC] = 1;
                }
            }
        }

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
