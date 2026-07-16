class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(auto it  :nums) {
            int index = abs(it) - 1;
            if(nums[index] < 0) return abs(it);
            nums[index] = nums[index] * -1;
        }
        return -1;
    }
};
