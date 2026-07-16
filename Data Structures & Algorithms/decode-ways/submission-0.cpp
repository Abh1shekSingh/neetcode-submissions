class Solution {
public:
    int solve(int i, string s, int n) {
        //base case
        if(i == n) return 1;
        if(s[i] == '0') return 0;
        //rec case
        int res = solve(i + 1, s, n);

        if(i + 1 < n) {
            if(s[i] == '1' || s[i] == '2' && s[i + 1] <= '6') {
                res += solve(i + 2, s, n);
            }
        }
        return res;
    }
    int numDecodings(string s) {
        int n = s.size();
        return solve(0, s, n);
    }
};
