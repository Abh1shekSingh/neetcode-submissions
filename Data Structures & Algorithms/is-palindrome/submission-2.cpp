class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(char ch : s) {
            if(ch != ' ' && (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9')) str+=tolower(ch);
        }
        string t = str;
        reverse(t.begin(), t.end());
        return t == str;
    }
};
