class Solution {
public:
    int calculate(string s) {

        int num = 0;
        int op = '+';
        stack<int> st;
        for (int i = 0; i <= s.size(); i++) {

            char ch = (i == s.size()) ? '+' : s[i];
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else if (ch != ' ') {
                if (op == '+') {
                    st.push(+num);
                } else if (op == '-') {
                    st.push(-num);
                } else if (op == '*') {
                    int poped = st.top();
                    st.pop();
                    st.push(poped * num);

                } else if (op == '/') {
                    int poped = st.top();
                    st.pop();
                    st.push(poped / num);
                }
                op = ch;
                num = 0;
            }
        }
        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};