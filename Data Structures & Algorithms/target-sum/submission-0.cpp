class Solution {
public:
    int solve(int i, int sum, vector<int>& nums, int t) {
        //base case
        if(i >= nums.size()) {
            if(sum == t) return 1;
            return 0;
        }

        //rec case
        int add = solve(i + 1, sum + nums[i], nums, t);
        int minus = solve(i + 1, sum - nums[i],nums, t);

        return add + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, 0, nums, target);
    }
};
