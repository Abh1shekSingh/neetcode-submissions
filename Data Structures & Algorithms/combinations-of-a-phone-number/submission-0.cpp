class Solution {
public:
    vector<string>res;
    vector<string> store = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(int index, string curr, string digits) {
        if(curr.size() == digits.size()) {
            res.push_back(curr);
            return;
        }

        string temp = store[digits[index] - '0'];
        for(auto c : temp) {
            solve(index + 1, curr + c, digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return res;
        solve(0, "", digits);
        return res;
    }
};
