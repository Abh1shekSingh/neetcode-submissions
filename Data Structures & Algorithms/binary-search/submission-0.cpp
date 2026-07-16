class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int hi = n - 1;

        while(low <= hi){
            int mid = (low + hi) / 2;

            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) {
                hi = mid - 1;
            }else {
                low = mid + 1;
            }
        }
        return -1;
    }
};
