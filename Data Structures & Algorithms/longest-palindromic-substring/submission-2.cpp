class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int startI = 0;
        int resLen = 0;
        vector<vector<bool>>dp(n, vector<bool>(n, false));
        for(int L = 1 ; L <= n ; L++) {
            for(int i = 0 ; i + L - 1 < n ; i++) {
                int j = i + L - 1;
                if(i == j) {
                    dp[i][i] = true;
                }else if(i + 1 == j) {
                    dp[i][j] = (s[i] == s[j]);
                }else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1] == true);
                }

                if(dp[i][j] && j - i + 1 > resLen) {
                    resLen = j - i + 1;
                    startI = i;
                }
            }
        }
        return s.substr(startI, resLen);
    }
};
