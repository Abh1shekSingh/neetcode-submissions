class Solution {
public:
    vector<int> dp;
    int solve(int i, vector<int>& nums, int n) {
        //base case
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        //rec case
        int take = nums[i] + solve(i + 2, nums, n);
        int notTake = solve(i + 1, nums, n);

        return dp[i] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, -1);
        return solve(0, nums, n);        
    }
};
