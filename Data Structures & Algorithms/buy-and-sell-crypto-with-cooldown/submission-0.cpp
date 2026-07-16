class Solution {
public:
    int dfs(int i, vector<int> p, int n, bool buy) {
        //rec case
        if(i >= n) {
            return 0;
        }
        //rec case
        int res = 0;
        if(buy) {
            int take = -p[i] + dfs(i + 1, p, n, false);
            int notTake = dfs(i + 1, p, n, true);
            return max(take, notTake);
        }else {
            int sell = p[i] + dfs(i + 2, p, n, true);
            int notSell = dfs(i + 1, p, n, false);
            return max(sell, notSell); 
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return dfs(0, prices, n, true);
    }
};
