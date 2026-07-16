class Solution {
public:
    int dx[4] = {0, 0, 1, -1}; 
    int dy[4] = {1, -1, 0, 0}; 
    void solve(int row, int col, vector<vector<int>>& h, vector<vector<int>>& ocean) {
        ocean[row][col] = 1;
        for(int i = 0 ; i < 4 ; i++) {
            int newR = row + dx[i];
            int newC = col + dy[i];
            if(newR >= 0 && newR < h.size() &&
               newC >= 0 && newC < h[0].size() &&
               h[newR][newC] >= h[row][col] && !ocean[newR][newC]) {
                solve(newR, newC, h, ocean);
               }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int ROWS = heights.size();
        int COLS = heights[0].size();
        vector<vector<int>> pac(ROWS, vector<int>(COLS, 0));
        vector<vector<int>> alt(ROWS, vector<int>(COLS, 0));

        for(int i = 0 ; i < ROWS ; i++) {
            solve(i, 0, heights, pac);
            solve(i, COLS - 1, heights, alt);
        }

        for(int i = 0 ; i < COLS ; i++) {
            solve(0, i, heights, pac);
            solve(ROWS - 1, i, heights, alt);
        }

        for(int i = 0 ; i < ROWS ; i++) {
            for(int j = 0 ; j < COLS ; j++){
                if(pac[i][j] && alt[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
