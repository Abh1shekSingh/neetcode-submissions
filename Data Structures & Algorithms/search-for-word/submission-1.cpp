class Solution {
public:
    vector<vector<bool>>vis;
    bool solve(vector<vector<char>>& board, int r, int c, string word, int k) {
        
        if(k == word.length()) {
            return true;
        }

        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[k] || vis[r][c]) {
            return false;
        }
        vis[r][c] = true;
        bool res = solve(board, r + 1, c,word, k + 1) ||
                   solve(board, r, c + 1,word, k + 1) ||
                   solve(board, r - 1, c,word, k + 1) ||
                   solve(board, r, c - 1,word, k + 1);
        vis[r][c] = false;

        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vis = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
        for(int r = 0 ; r < n ; r++) {
            for(int c = 0 ; c < m ; c++) {
                if(solve(board, r, c, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
