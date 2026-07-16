class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>&res,int index, int size) {
        //base case
        if(index >=size ) {
            ans.push_back(res);
            return ;
        }

        //rec case
        res.push_back(nums[index]);
        solve(nums, ans, res,index + 1, size);
        res.pop_back();
        solve(nums, ans,res, index + 1, size);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
         int n = nums.size();
        solve(nums, ans,res, 0, n);
        return ans;
    }
};
