class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int solve(int i, int j, vector<vector<int>>& matrix, int row, int col) {
        if(i < 0 || i >= row || j < 0 || j >= col) return 0;
        //rec case
        int ans = 1;
        for(int k = 0 ; k < 4 ; k++) {
            int newR = i + dx[k];
            int newC = j + dy[k];
            if(newR >= 0 && newR < row && newC >= 0 && newC < col && matrix[newR][newC] > matrix[i][j]) {
                ans = max(ans, 1 + solve(newR, newC, matrix, row, col));
            }
        }
        return ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int ans = 1;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++) {
                ans = max(ans, solve(i, j, matrix, row, col));
            }
        }
        return ans;
    }
};
