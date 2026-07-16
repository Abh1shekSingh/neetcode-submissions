class Solution {
public:
    int solve(string a, string b, int n, int m) {
        if(n == 0 || m == 0) {
            return n == 0 ? m : n;
        }
        //rec case
        if(a[n - 1] == b[m - 1]) {
            return solve(a, b, n - 1, m - 1);
        }else {
            return 1 + min({solve(a, b, n - 1, m - 1), solve(a, b, n - 1, m), solve(a, b, n, m - 1)});
        }
    }
    int minDistance(string word1, string word2) {
         int n = word1.size();
         int m = word2.size();

         return solve(word1, word2, n, m);
    }
};
