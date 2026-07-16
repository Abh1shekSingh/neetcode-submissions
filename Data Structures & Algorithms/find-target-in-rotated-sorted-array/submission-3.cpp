class Solution {
public:
    int findPivot(int low, int hi, vector<int>& nums) {
        while(low <= hi) {
            if(nums[low] <= nums[hi]) return low;
            int mid = (low + hi) / 2;

            if(nums[mid] > nums[hi]) {
                low = mid + 1;
            }else {
                hi = mid;
            }
        }
        return low;
    }
    int binarySearch(int low, int hi, vector<int>& nums, int t) {
        while(low <= hi) {
            int mid = (low + hi) / 2;
            if(nums[mid] == t) return mid;
            if(nums[mid] > t) {
                hi = mid - 1;
            }else {
                low = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        //find pivot to ensure which segment to choose.
        //then again lgao Binary search

        int n = nums.size();

        int pivot = findPivot(0, n - 1, nums);

        if(nums[pivot]==target) return pivot;
        int ans = -1;
        if(pivot == 0) {
            return binarySearch(0, n - 1, nums, target);
        }
        if(nums[0] <= target) {
            return binarySearch(0, pivot - 1, nums, target);
        }
        return binarySearch(pivot + 1, n - 1, nums, target);
    }
};
