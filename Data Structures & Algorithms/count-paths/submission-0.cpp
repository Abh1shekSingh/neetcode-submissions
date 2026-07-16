class Solution {
public:
    int solve(int ans, int m, int n) {
        //base case
        if(m <= 0 || n <= 0) return 1;
        if(m == 0 && n == 0) return ans;
        //rec case
        return solve(ans + 1, m - 1, n) + solve(ans + 1, m, n - 1);
    }
    int uniquePaths(int m, int n) {
        return solve(0, m - 1, n - 1);
    }
};
