class Solution {
public:
    vector<int> dp, dp_last;
    int solve(int i, int n, vector<int>& nums) {
        //base case
        if(i >= n - 1) return 0;
        if(dp_last[i] != -1) return dp_last[i];
        //rec case
        int take = nums[i] + solve(i + 2, n, nums);
        int notTake = solve(i + 1, n, nums);

        return dp_last[i] = max(take, notTake);
    }
    int solve_last(int i, int n, vector<int>& nums) {
        //base case
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        //rec case
        int take = nums[i] + solve_last(i + 2, n, nums);
        int notTake = solve_last(i + 1, n, nums);

        return dp[i] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if( n == 1 ) return nums[0];
        dp.resize(n, -1);
        dp_last.resize(n, -1);
        return max(solve(0, n, nums), solve_last(1, n, nums));
    }
};
