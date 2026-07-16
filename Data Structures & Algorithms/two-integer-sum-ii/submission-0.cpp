class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> mp;
        int n = numbers.size();
        vector<int> res;
        for(int i = 0 ; i < n ; i++) {
            if(mp.find(target - numbers[i]) != mp.end()) {
                res.push_back(mp[target - numbers[i]] + 1);
                res.push_back(i + 1);
            }
            mp[numbers[i]] = i;
        }
        return res;
    }
};
