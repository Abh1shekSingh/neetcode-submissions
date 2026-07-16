class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int L = 1 ; L <= s.size() ; L++) {
            for(int i = 0 ; i + L - 1 < s.size() ; i++) {
                int j = i + L - 1;

                if(i == j) dp[i][i] = 1;
                else if(i + 1 == j) dp[i][j] = (s[i] == s[j]);
                else dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);

                if(dp[i][j]) count++;
            }
        }
        return count;
    }
};
