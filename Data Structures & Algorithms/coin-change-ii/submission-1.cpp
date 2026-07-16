class Solution {
public:
    int solve(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        //base case
        if(amount == 0) return 1;
        if(i >= coins.size()) {
            return 0;
        }

        if(dp[i][amount] != -1) return dp[i][amount];

        //rec case
        int res = 0;
        if(amount >= coins[i]) {
            res = solve(i + 1, amount, coins, dp);
            res += solve(i, amount - coins[i], coins, dp);
        }
        dp[i][amount] = res;
        return res;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        sort(coins.begin(), coins.end());
        return solve(0, amount, coins, dp);
    }
};
