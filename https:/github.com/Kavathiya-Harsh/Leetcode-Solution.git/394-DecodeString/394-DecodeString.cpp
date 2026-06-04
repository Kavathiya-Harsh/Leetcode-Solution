// Last updated: 6/4/2026, 11:07:00 AM
1class Solution {
2public:
3    string decodeString(string s) {
4        stack<int> numStack;
5        stack<string> strStack;
6
7        string currStr = "";
8        int num = 0;
9
10        for (char ch : s) {
11            if (isdigit(ch)) {
12                num = num * 10 + (ch - '0');
13            }
14            else if (ch == '[') {
15                numStack.push(num);
16                strStack.push(currStr);
17
18                num = 0;
19                currStr = "";
20            }
21            else if (ch == ']') {
22                int repeat = numStack.top();
23                numStack.pop();
24
25                string prevStr = strStack.top();
26                strStack.pop();
27
28                string temp = "";
29                for (int i = 0; i < repeat; i++) {
30                    temp += currStr;
31                }
32
33                currStr = prevStr + temp;
34            }
35            else {
36                currStr += ch;
37            }
38        }
39
40        return currStr;
41    }
42};