class Solution {
public:
    bool isPalindrome(int i, int j, string s) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string res = "";
        int resLen = 0;
        int startI = 0;

        for(int i = 0 ; i < s.size() ; i++) {
            for(int j = i ; j < s.size() ; j++) {
                if(isPalindrome(i, j, s) && j - i + 1 > resLen) {
                    resLen = j - i + 1;
                    startI = i;
                }
            }
        }
        res = s.substr(startI, resLen);
        return res;
    }
};
