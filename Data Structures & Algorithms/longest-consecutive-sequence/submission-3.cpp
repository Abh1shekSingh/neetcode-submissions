class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for(int i = 0 ; i < n ; i++) {
            st.insert(nums[i]);
        }
        int ans = 0;
        int curr = 0;
        for(int i = 0 ; i < n ; i++) {
            if(st.find(nums[i] - 1) == st.end()) {
                int currNum = nums[i];
                curr = 1;
                while(st.find(currNum + 1) != st.end()) {
                    curr++;
                    currNum++;
                }
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};
