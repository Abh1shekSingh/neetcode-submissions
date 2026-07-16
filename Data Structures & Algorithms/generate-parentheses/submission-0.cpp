class Solution {
public:
    bool valid(string s) {
        int open = 0;
        for(char ch : s) {
            if(ch == '(') {
                open += 1;
            }else {
                open -= 1;
            }
            if(open < 0) return false;
        }
        return open == 0;
    }
    void solve(string s, vector<string>& res, int n) {
        if(s.size() == 2*n) {
            if(valid(s)) res.push_back(s);
            return ;
        }
        solve(s + '(', res, n);
        solve(s + ')', res, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve("", res, n);
        return res;
    }
};
