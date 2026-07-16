class Solution {
public:
    int solve(int i, vector<int>& nums, int j, vector<vector<int>>& dp) {
        //base case
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        //rec case
        int res = INT_MIN;
        for(int ind = i ; ind <= j ; ind++) {
            int cost = (nums[i - 1] * nums[ind] * nums[j + 1]) + solve(i, nums, ind - 1, dp) + solve(ind + 1, nums, j, dp);
            res = max(res, cost);
        }
        return dp[i][j] = res;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        return solve(1, nums, n, dp);
    }
};
