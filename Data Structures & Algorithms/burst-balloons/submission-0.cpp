class Solution {
public:
    int solve(int i, vector<int>& nums, int j) {
        //base case
        if(i > j) return 0;

        //rec case
        int res = INT_MIN;
        for(int ind = i ; ind <= j ; ind++) {
            int cost = (nums[i - 1] * nums[ind] * nums[j + 1]) + solve(i, nums, ind - 1) + solve(ind + 1, nums, j);
            res = max(res, cost);
        }
        return res;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        return solve(1, nums, n);
    }
};
