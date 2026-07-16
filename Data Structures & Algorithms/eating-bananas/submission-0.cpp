class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int mid) {
        int n = piles.size();
        int time = 0;

        for(int i = 0 ; i < n ; i++) {
            if(piles[i] % mid != 0) time+=1;
            time+=(piles[i]/mid);
        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int hi = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while(low <= hi) {
            int mid = (low + hi) / 2;

            if(isPossible(piles, h, mid)) {
                ans = mid;
                hi = mid - 1;
            }else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
