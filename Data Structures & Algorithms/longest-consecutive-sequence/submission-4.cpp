class Solution {
public:
    int solve(int index, int prev, vector<int>& nums, int size) {
        //base case
        if(index >= size) {
            return 0;
        }

        //rec case
        int choose = INT_MIN;
        int notChoose = solve(index + 1, prev, nums, size);
        
        if(prev == -1 || nums[index] == nums[prev] + 1) {
            choose = 1 + solve(index + 1, index, nums, size);
        }

        return max(choose, notChoose);
    }
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int n = nums.size();
        return solve(0, -1, nums, n);
    }
};