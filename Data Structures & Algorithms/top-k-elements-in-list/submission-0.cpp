class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++) {
            mp[nums[i]]++;
        }
        vector<pair<int, int>> store;

        for(auto it :  mp) {
            store.push_back({it.second, it.first});
        }

        sort(store.rbegin(), store.rend());
        vector<int> res;
        for(int i = 0 ; i < k ; i++) {
            res.push_back(store[i].second);
        }
        return res;
    }
};
