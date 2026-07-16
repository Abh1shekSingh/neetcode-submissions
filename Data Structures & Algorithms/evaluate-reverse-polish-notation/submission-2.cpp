class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        int n = tokens.size();

        for(int i = 0 ; i < n ; i++) {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
               if(!st.empty()) {
                    int a = stoi(st.top());
                    st.pop();
                    int b = stoi(st.top());
                    st.pop();
                    int res = 0;
                    if(tokens[i] == "+") {
                        res = a + b;
                        st.push(to_string(res));
                    }else if(tokens[i] == "-") {
                        res = b - a;
                        st.push(to_string(res));
                    }else if(tokens[i] == "*") {
                        res = a*b;
                        st.push(to_string(res));
                    }else if(tokens[i] == "/") {
                        res = b/a;
                        st.push(to_string(res));
                    }
               } 
            }else {
                st.push(tokens[i]);
            }
        }
        return stoi(st.top());
    }
};
