class Solution {
public:
    string encode(vector<string>& strs) {
        string s;
        if (strs.size() == 0) {
            return s; 
        }

        for (const string& str : strs) {
            s += to_string(str.length()) + "#" + str; 
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.length()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j - i));
            res.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }
        return res;
    }
};