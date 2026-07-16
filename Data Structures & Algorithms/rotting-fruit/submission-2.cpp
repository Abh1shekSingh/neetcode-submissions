class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int freshCnt = 0;
        int time = 0;
        queue<pair<int, int>> que;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == 1) {
                    freshCnt++;
                }
                if(grid[i][j] == 2) {
                    que.push({i, j});
                }
            }
        }

        while(freshCnt && !que.empty()) {
            int size = que.size();
            while(size--) {
                int row = que.front().first;
                int col = que.front().second;

                que.pop();

                for(int i = 0 ; i < 4 ; i++) {
                    int newR = row + dx[i];
                    int newC = col + dy[i];

                    if(newR >= 0 && newR < n &&
                       newC >= 0 && newC < m &&
                       grid[newR][newC] == 1) {
                        que.push({newR, newC});
                        grid[newR][newC] = 2;
                        freshCnt--;
                       }
                }
            }
            time++;
        }
        return freshCnt == 0 ? time : -1;
    }
};
