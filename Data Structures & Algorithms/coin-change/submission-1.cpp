class Solution {
public:
    unordered_map<int, int> dp;
    int dfs(vector<int>& coins, int amount) {
        //base case
        if(amount == 0) return 0;
        if(dp.find(amount) != dp.end()) return dp[amount];
        //rec case
        int ans = 1e9;
        for(auto coin : coins) {
            if(amount - coin >= 0) {
                int result = dfs(coins, amount - coin);
                if(result != 1e9) {
                    ans = min(ans, result+ 1);
                }
            }
        }
        
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = dfs(coins, amount);
        return (ans >= 1e9) ? -1 : ans;
    }
};
