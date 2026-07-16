class Solution {
public:
    vector<vector<string>>res;
    bool isValid(int row, int col, vector<string>& board, int n) {
        int r = row , c = col;
        //upper diagonal
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') {
                return false;
            }
            row--;
            col--;
        }
        //sameline check
        row = r;
        col = c;
        while(col >= 0) {
            if(board[row][col] =='Q') return false;
            col--;
        }
        //lower diagonal
        row = r;
        col = c;
        while(row < n && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(vector<string>& board, int n, int col) {
        //base case
        if(col == n) {
            res.push_back(board);
            return ;
        }

        for(int row = 0 ; row < n ; row++) {
            if(isValid(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(board, n, col + 1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<string> board(n);
        for(int i = 0 ; i < n ; i++) {
            board[i] = s;
        }   

        solve(board, n, 0);
        return res;
    }
};
