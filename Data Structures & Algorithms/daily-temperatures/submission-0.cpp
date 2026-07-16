class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> st;
        int n = t.size();
        vector<int> res(n, 0);
        for(int i = 0 ; i < n ; i++) {
            if(st.empty()) {
                st.push(i);
            }else if(!st.empty() && t[i] > t[st.top()]) {
                while(!st.empty() && t[i] > t[st.top()]) {
                    res[st.top()] = i - st.top();
                    st.pop();
                }
            }
            st.push(i);
        }
        return res;
    }
};
