class Solution {
public:
    int ans;
    int solve(int i, vector<int>& nums, int j) {
        //base case
        if(i >= nums.size()) return 0;
        //rec case
        int notTake = solve(i + 1, nums, j);
        int take = 0;
        if(j == -1 || nums[j] < nums[i]) {
             take = 1 + solve(i + 1, nums, i);
        }
        return max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return solve(0, nums, -1);
    }
};
