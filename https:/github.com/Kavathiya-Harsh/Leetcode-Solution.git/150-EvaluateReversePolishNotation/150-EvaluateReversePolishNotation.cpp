// Last updated: 6/4/2026, 11:45:15 AM
1class Solution {
2public:
3    int evalRPN(vector<string>& tokens) {
4        stack<int> st;
5
6        for (string token : tokens) {
7
8            if (token == "+" || token == "-" || token == "*" || token == "/") {
9
10                int b = st.top();
11                st.pop();
12
13                int a = st.top();
14                st.pop();
15
16                if (token == "+")
17                    st.push(a + b);
18                else if (token == "-")
19                    st.push(a - b);
20                else if (token == "*")
21                    st.push(a * b);
22                else
23                    st.push(a / b);
24            } else {
25                st.push(stoi(token));
26            }
27        }
28
29        return st.top();
30    }
31};