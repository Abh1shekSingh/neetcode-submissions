class Solution {
public:
    vector<vector<int>> ans;
    set<int> mp;
    void solve(vector<int>& nums, vector<int>& res) {
        //base case
        if(res.size() == nums.size()) {
            ans.push_back(res);
            return ;
        }

        //rec case
        for(int i = 0 ; i < nums.size() ; i++) {
            if(mp.find(nums[i]) == mp.end()) {
                res.push_back(nums[i]);
                mp.insert(nums[i]);
                solve(nums, res);
                res.pop_back();
                mp.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> res;
        solve(nums, res);
        return ans;
    }
};
