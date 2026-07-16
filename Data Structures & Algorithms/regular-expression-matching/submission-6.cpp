class Solution {
public:
    bool solve(string s, string p) {
        //base case
        if(p.size() == 0) {
            if(s.size() == 0) return true;
            return false;
        }

        //rec case
        bool firstCharMatched = false;
        if(s.size() > 0 && ((s[0] == p[0]) || p[0] == '.')) {
            firstCharMatched = true;
        }

        if(p.size() > 0 && p[1] == '*') {
            bool notTake = solve(s, p.substr(2));
            bool take = firstCharMatched && solve(s.substr(1), p);
            return notTake || take;
        }else {
            return firstCharMatched && solve(s.substr(1), p.substr(1));
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        return solve(s, p);
    }
};
