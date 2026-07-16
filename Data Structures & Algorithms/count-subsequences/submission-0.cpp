class Solution {
public:
    int solve(string a, string b, int i, int j, int n, int m) {
        //base case
        if(j == m) return 1;
        if(i == n) return 0;

        //rec case
        int res = solve(a, b, i + 1, j, n, m);
        if(a[i] == b[j]) {
            res += solve(a, b, i + 1, j + 1, n, m);
        }
        return res;
    }
    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();
        if(m > n) return 0;
        return solve(s, t, 0, 0, n, m);
    }
};
