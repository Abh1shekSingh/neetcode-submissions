class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& res, int target, int index) {
        //base case
        if(target == 0) {
            ans.push_back(res);
            return ;
        }
        if(index >= nums.size() || target < 0) return ;
        //rec case
            res.push_back(nums[index]);
            solve(nums, ans, res, target - nums[index], index);
            res.pop_back();
            solve(nums, ans, res, target, index + 1);
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        solve(nums, ans, res, target, 0);
        return ans;
    }
};
