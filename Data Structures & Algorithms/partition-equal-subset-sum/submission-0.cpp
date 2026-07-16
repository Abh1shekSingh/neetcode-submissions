class Solution {
public:
    bool solve(int i, vector<int>& nums, int t) {
        //base case
        if(i >= nums.size()) {
            if(t == 0) return true;
            return false;
        }
        if(t < 0) return false;
        //rec case
        return solve(i + 1, nums, t) || solve(i + 1, nums, t - nums[i]);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto it : nums) sum += it;
        if(sum % 2 != 0) return false;
        return solve(0, nums, sum / 2);

    }
};
