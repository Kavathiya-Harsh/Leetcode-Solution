// Last updated: 6/4/2026, 10:30:23 AM
1class Solution {
2public:
3    int waviness(string &s) {
4        int cnt = 0;
5
6        for (int i = 1; i < s.size() - 1; i++) {
7            if ((s[i] > s[i - 1] && s[i] > s[i + 1]) ||
8                (s[i] < s[i - 1] && s[i] < s[i + 1])) {
9                cnt++;
10            }
11        }
12
13        return cnt;
14    }
15
16    int totalWaviness(int num1, int num2) {
17        int ans = 0;
18
19        for (int num = num1; num <= num2; num++) {
20            string s = to_string(num);
21            ans += waviness(s);
22        }
23
24        return ans;
25    }
26};