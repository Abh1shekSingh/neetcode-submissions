class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> que;

        for(int i = 0 ; i < k ; i++) {
            que.push({nums[i], i});
        }

        int maxi = que.top().first;
        vector<int> ans;
        ans.push_back(maxi);
        for(int i = k ; i < n ; i++) {
            que.push({nums[i], i});
            while(que.top().second <= i - k) {
                que.pop();
            }
            ans.push_back(que.top().first);
        }
        return ans;
    }
};
