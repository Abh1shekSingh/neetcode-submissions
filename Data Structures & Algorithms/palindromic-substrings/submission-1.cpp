class Solution {
public:
    int count;
    Solution() {
        count = 0;
    }
    void check(int i, int j, int n, string& s) {
        while(i >= 0 && j < n && s[i] == s[j]) {
            i--;
            j++;
            count++;
        }
    }
    int countSubstrings(string s) {
        int n = s.size();

        for(int i = 0 ; i < n ; i++) {
            check(i,i,n,s);
            check(i,i + 1,n,s);
        }
        return count;
    }
};
