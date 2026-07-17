class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        unordered_map<char, int> tp, sp;
        if(s.size() < t.size()) return "";
        for(int i = 0 ; i < t.size() ; i++) {
            tp[t[i]]++;
        }

        int i = 0;
        int index = -1;
        int count = 0;
        int minLen = INT_MAX;
        for(int j = 0 ; j < n ; j++) {
            sp[s[j]]++;
            //char match
            if(sp[s[j]] <= tp[s[j]]) {
                count++;
            }

            if(count == t.size()) {
                //minimize window

                while(sp[s[i]] > tp[s[i]]) {
                    if(sp[s[i]] > tp[s[i]]) {
                        sp[s[i]]--;
                    }
                    i++;
                }

                int len = j - i + 1;
                if(minLen > len) {
                    minLen = len;
                    index = i;
                }
            }
        }
        if(index == -1) return "";
        return s.substr(index, minLen);
    }
};
