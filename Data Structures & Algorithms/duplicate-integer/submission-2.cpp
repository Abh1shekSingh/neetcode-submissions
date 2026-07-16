class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        set<int> vis;

        for(int i = 0 ; i < n ; i++) {
            if(vis.count(nums[i])) return true;
            else vis.insert(nums[i]);
        } 
        return false;
    }
};
