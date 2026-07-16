class Solution {
public:
    vector<vector<string>> ans;
    bool palin(string s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void solve(string &s, int j, int i, vector<string>& temp){
        //base case
        if(i >= s.size()) {
            if(i == j) {
                ans.push_back(temp);
            }
            return ;
        }

        //rec case
        if(palin(s, j, i)) {
            temp.push_back(s.substr(j, i - j + 1));
            solve(s, i + 1, i + 1, temp);
            temp.pop_back();
        }
        solve(s, j, i + 1, temp);
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(s, 0, 0, temp);
        return ans;
    }
};
