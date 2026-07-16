class Solution {
public:
    vector<int> NSE(vector<int>& arr, int n) {
        vector<int> ans(n);
        stack<int> st;
        for(int i = 0 ; i < n ; i++) {
            if(st.empty()) {
                ans[i] = -1;
                st.push(i);
            }else {
                if(arr[i] > arr[st.top()]) {
                    ans[i] = st.top();
                    st.push(i);
                }else {
                    while(!st.empty() && arr[i] <= arr[st.top()]) {
                        st.pop();
                    }
                    if(st.empty()) {
                        ans[i] = -1;
                        st.push(i);
                    }else {
                        ans[i] = st.top();
                        st.push(i);
                    }
                }
            }
        }
        return ans;
    }
    vector<int> PSE(vector<int>& arr, int n) {
        vector<int> ans(n);
        stack<int> st;
        for(int i = n - 1 ; i>= 0 ; i--) {
            if(st.empty()) {
                ans[i] = n;
                st.push(i);
            }else {
                if(arr[i] > arr[st.top()]) {
                    ans[i] = st.top();
                    st.push(i);
                }else {
                    while(!st.empty() && arr[i] <= arr[st.top()]) {
                        st.pop();
                    }
                    if(st.empty()) {
                        ans[i] = n;
                        st.push(i);
                    }else {
                        ans[i] = st.top();
                        st.push(i);
                    }
                }
            }
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        // Find NSE and PSE
        int n = heights.size();
        vector<int> pse = PSE(heights,n);
        vector<int> nse = NSE(heights,n);
        vector<int> area(n);
        for(int i = 0 ; i < n ; i++) {
            int w = pse[i] - nse[i] - 1;
            area[i] = heights[i] * w;
        }
        return *max_element(area.begin(), area.end());
    }
};
