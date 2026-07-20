class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>cnt1(26, 0);
        

        for(auto ch : s1) {
            cnt1[ch - 'a']++;
        }

        for(int i = 0 ; i < s2.size()  ; i++) {
            bool flag = true;
            vector<int>cnt2(26, 0);
            string str = s2.substr(i, s1.size());
            for(auto ch : str) {
                cnt2[ch - 'a']++;
            }

            for(int j = 0 ; j < 26 ; j++) {
                if(cnt1[j] != cnt2[j]) {
                    flag = false;
                    break;
                }
            }

            if(flag) return true;
        }
        return false;
    }
};
