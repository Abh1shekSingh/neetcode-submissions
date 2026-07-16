class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for(auto s : strs) {
            string word = s;
            sort(word.begin(), word.end());
            mp[word].push_back(s);
        }

        for(auto it : mp) {
            vector<string> x = it.second;
            ans.push_back(x);
        }
        return ans;
    }
};
