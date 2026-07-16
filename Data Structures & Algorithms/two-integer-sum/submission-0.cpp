class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> mp;
        vector<int> res;
        for(int i = 0 ; i < n ; i++) {
            // a = t - b;
            if(mp.find(target - nums[i]) != mp.end()) {
                res.push_back(mp[target - nums[i]]);
                res.push_back(i);
            }
            mp[nums[i]] = i;

        }
        return res;
    }
};
