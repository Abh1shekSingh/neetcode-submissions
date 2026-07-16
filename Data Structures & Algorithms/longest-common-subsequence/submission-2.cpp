class Solution {
public:
    
    int solve(string a, string b, int m, int n, vector<vector<int>>& dp) {
        //base case
        if(m == 0 || n == 0) {
            return 0;
        }
        if(dp[m][n] != -1) return dp[m][n];
        //rec case
        if(a[m - 1] == b[n - 1]) return dp[m][n] = 1 + solve(a, b, m - 1, n - 1, dp);
        else {
            return dp[m][n] = max(solve(a, b, m - 1, n, dp), solve(a, b, m, n - 1, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(text1, text2, m, n, dp);
    }
};
