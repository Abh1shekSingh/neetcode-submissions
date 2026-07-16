class Solution {
public:
vector<vector<int>> ans;
void solve(vector<int>& nums, vector<int>& res, int target, int index, int sum) {
        //base case
        if(target == sum) {
            ans.push_back(res);
            return ;
        }
        if(index == nums.size() || sum > target) return ;
        //rec case
            res.push_back(nums[index]);
            solve(nums,  res, target , index + 1 , sum + nums[index]);
            res.pop_back();
            while(index + 1 < nums.size() && nums[index] == nums[index + 1]) index++;
            solve(nums, res, target, index + 1, sum);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();
        vector<int> res;
        sort(candidates.begin(), candidates.end());
        solve(candidates, res, target, 0 ,0);
        return ans;
    }
};
