class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = INT_MIN;
        for(int i = 0 ; i < prices.size() ; i++) {
            int minPrice = min(minPrice, prices[i]);
            ans = max(ans, prices[i] - minPrice);
        }
        return ans;
    }
};
