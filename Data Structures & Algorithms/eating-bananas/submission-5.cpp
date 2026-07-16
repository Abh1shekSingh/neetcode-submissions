class Solution {
public:
    int n;
    bool check(vector<int>& piles, int time, int maxTime) {
        int cnt = 0;
        for(int i = 0 ; i < n ; i++) {
            if(piles[i] % time != 0) cnt++;
            cnt += piles[i] / time;
        }
        return cnt <= maxTime;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        n = piles.size();
        int low = 1;
        int hi = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while(low <= hi) {
            int mid = low + (hi - low) / 2;
            if(check(piles, mid, h)) {
                ans = mid;
                hi = mid - 1;
            }else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
